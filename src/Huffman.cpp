#include "Huffman.h"


Huffman::Huffman()
{
	srand((unsigned int)time(nullptr));
	filepath = readFile();
	analyzeData();
	huffmanTree();
	makeHeader();
	compressFile();
	outputCompressedFile();
}

Huffman::~Huffman() = default;

std::string Huffman::readFile()
{
	std::string filepath;
	std::cout << "Input path to file to be compressed:\n";
	std::cin >> filepath;
	std::ifstream reader;
	reader.open(filepath, std::ios_base::binary);
	char readChar;
	while (reader.get(readChar))
	{
		readData.push_back(readChar);
	}
	reader.close();
	return filepath;
}

void Huffman::analyzeData()
{
	for (char c : readData) {
		auto it = byteTokens.find(c);
		if (it != byteTokens.end())
		{
			it->second.increaseCount();
			continue;
		}
		ByteToken bt(c);
		std::pair<char, ByteToken> p(c, bt);
		byteTokens.insert(p);
	}
}

void Huffman::huffmanTree()
{
	for (auto &byteToken : byteTokens) {
		huffman.push(Node(byteToken.second.getKey(), byteToken.second.getCount(), nullptr, nullptr));
	}

	while (huffman.size() > 1)
	{
		Node n1 = huffman.top();
		huffman.pop();

		Node n2 = huffman.top();
		huffman.pop();

		auto n1Pointer = new Node(n1.getKey(), n1.getCount(), n1.getN1(), n1.getN2());
		auto n2Pointer = new Node(n2.getKey(), n2.getCount(), n2.getN1(), n2.getN2());
		storedNodes.push_back(n1Pointer);
		storedNodes.push_back(n2Pointer);

		Node n3(NULL, n1.getCount() + n2.getCount(), n1Pointer, n2Pointer);
		huffman.push(n3);
	}
	extractCodes(huffman.top(), "");
}

void Huffman::extractCodes(Node n, std::string code)
{
	if (n.getN1() != nullptr)
	{
		extractCodes(*(n.getN1()), code + "0");
	}
	if (n.getN2() != nullptr)
	{
		extractCodes(*(n.getN2()), code + "1");
	}
	if (n.getN1() != nullptr || n.getN2() != nullptr)
		return;

	char c = n.getKey();
	byteTokens[c].setCode(code);
}

void Huffman::compressFile()
{
	/*
	int slashIndex = filepath.find_last_of('/');
	int dotIndex = filepath.find_last_of('.');
	if (slashIndex = -1)
	slashIndex = 0;
	string filename = filepath.substr(slashIndex, dotIndex - slashIndex);
	ofstream writer;
	writer.open(filename + ".compressed");


	writer << header;
	*/
	compressedData.emplace_back("");
	int counter = 0;
	unsigned char c = 0;
	for (char i : readData) {
		std::string code = byteTokens[i].getCode();
		unsigned long codeSize = code.size();
		unsigned long codeIndex = 0;
		while (codeIndex < codeSize)
		{
			char codeBit = code.at(codeIndex);
			if (codeBit == '1')
				c = c | (unsigned char)1;
			c = c << 1u;
			codeIndex++;
			counter++;

			if (counter == 8)
			{
				counter = 0;
				//compressedData.push_back(c);
				//writer << c;
				compressedData[0] += c;
				c = 0;
			}

		}
	}

	while (counter < 8)
	{
		c = c << 1u;
		counter++;
	}
	compressedData[0] += c;
	//writer << c;
	//writer.close();
	//compressedData.push_back(c);
}

void Huffman::outputCompressedFile()
{
	std::cout << "Outputting file\n";
	std::size_t slashIndex = filepath.find_last_of('/');
	if (slashIndex == -1)
		slashIndex = 0;
	std::string filename = filepath.substr(slashIndex + 1);
	std::ofstream writer;
	writer.open(filename + ".compressed");

	writer << header;

	for (const auto &i : compressedData) {
		writer << i;
	}
	writer.close();
}

void Huffman::makeHeader()
{
	header = "";
	auto it = byteTokens.begin();
	auto nTokens = (char)byteTokens.size();
	header += nTokens;
	for (it; it != byteTokens.end(); it++)
	{
		const char byteToken = it->first;
		std::vector<unsigned char> code = codeStringToBytes(it->second.getCode());
		unsigned long codeLength = it->second.getCode().size();
		header += byteToken;
		header += std::to_string(codeLength);
		for (unsigned char j : code) {
			header += j;
		}
	}
}

std::vector<unsigned char> Huffman::codeStringToBytes(std::string code)
{
	std::vector<unsigned char> ret;
	unsigned char c = 0;
	int counter = 0;
	unsigned long codeSize = code.size();
	unsigned long codeIndex = 0;
	while (codeIndex < codeSize)
	{
		char codeBit = code.at(codeIndex);
		if (codeBit == '1')
			c = c | (unsigned char)1;
		c = c << 1u;
		codeIndex++;
		counter++;

		if (counter == 8)
		{
			counter = 0;
			ret.push_back(c);
			c = 0;
		}
	}

	while (counter < 8)
	{
		c = c << 1u;
		counter++;
	}

	ret.push_back(c);
	return ret;
}