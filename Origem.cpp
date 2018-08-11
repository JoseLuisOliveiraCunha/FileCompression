#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <queue>
#include <unordered_map>

#include "byteToken.h"
#include "Node.h"

using namespace std;

vector<char> readData;
vector<unsigned char> compressedData;
unordered_map<char, byteToken> byteTokens;
priority_queue<Node> huffman;
vector<Node *> storedNodes;
string filepath;
string header;

string readFile();
void analyzeData();
void huffmanTree();
void extractCodes(Node n, string code);
void compressFile();
void makeHeader();
vector<unsigned char> codeStringToBytes(string code);
//void outputCompressedFile(string filepath);

int main()
{
	srand(time(NULL));
	filepath = readFile();
	analyzeData();
	huffmanTree();
	makeHeader();
	compressFile();
	//outputCompressedFile(filepath);

	return 0;
}

string readFile() 
{
	string filepath;
	cout << "Input path to file to be compressed:\n";
	cin >> filepath;
	ifstream reader;
	reader.open(filepath, ios_base::binary);
	char readChar;
	while (reader.get(readChar))
	{
		readData.push_back(readChar);
	}
	reader.close();
	return filepath;
}

void analyzeData() 
{
	for (unsigned long i = 0; i < readData.size(); i++)
	{
		char c = readData[i];
		unordered_map<char, byteToken>::iterator it = byteTokens.find(c);
		if (it != byteTokens.end())
		{
			it->second.increaseCount();
			continue;
		}
		byteToken bt(c);
		pair<char, byteToken> p(c, bt);
		byteTokens.insert(p);
	}
}

void huffmanTree() 
{
	for (unordered_map<char, byteToken>::iterator it = byteTokens.begin(); it != byteTokens.end(); it++)
	{
		huffman.push(Node(it->second.getKey(), it->second.getCount(), NULL, NULL));
	}

	while (huffman.size() > 1)
	{
		Node n1 = huffman.top();
		huffman.pop();
		
		Node n2 = huffman.top();
		huffman.pop();
		
		Node* n1Pointer = new Node(n1.getKey(), n1.getCount(), n1.getN1(), n1.getN2());
		Node* n2Pointer = new Node(n2.getKey(), n2.getCount(), n2.getN1(), n2.getN2());
		storedNodes.push_back(n1Pointer);
		storedNodes.push_back(n2Pointer);

		Node n3(NULL, n1.getCount() + n2.getCount(), n1Pointer, n2Pointer);
		huffman.push(n3);
	}
	extractCodes(huffman.top(), "");
}

void extractCodes(Node n, string code)
{
	if (n.getN1() != NULL)
	{
		extractCodes(*(n.getN1()), code + "0");
	}
	if (n.getN2() != NULL)
	{
		extractCodes(*(n.getN2()), code + "1");
	}
	if (n.getN1() != NULL || n.getN2() != NULL)
		return;

	char c = n.getKey();
	byteTokens[c].setCode(code);
}

void compressFile()
{
	//
	int slashIndex = filepath.find_last_of('/');
	int dotIndex = filepath.find_last_of('.');
	if (slashIndex = -1)
		slashIndex = 0;
	string filename = filepath.substr(slashIndex, dotIndex - slashIndex);
	ofstream writer;
	writer.open(filename + ".compressed");
	//

	writer << header;

	int counter = 0;
	unsigned char c = 0;
	for (unsigned long i = 0; i < readData.size(); i++)
	{
		string code = byteTokens[readData[i]].getCode();
		int codeSize = code.size();
		int codeIndex = 0;
		while (codeIndex < codeSize)
		{
			char codeBit = code.at(codeIndex);
			if(codeBit == '1')
				c = c | (unsigned char)1;
			c = c << 1;
			codeIndex++;
			counter++;
			
			if (counter == 8)
			{
				counter = 0;
				//compressedData.push_back(c);
				writer << c;
				c = 0;
			}
			
		}
	}

	while (counter < 8)
	{
		c = c << 1;
		counter++;
	}
	writer << c;
	writer.close();
	//compressedData.push_back(c);
}

/*void outputCompressedFile(string filepath)
{
	int slashIndex = filepath.find_last_of('/');
	int dotIndex = filepath.find_last_of('.');
	if (slashIndex = -1)
		slashIndex = 0;
	string filename = filepath.substr(slashIndex, dotIndex - slashIndex);
	
	ofstream writer;
	writer.open(filename + ".compressed");
	for (unsigned long i = 0; i < compressedData.size(); i++) {
		writer << compressedData[i];
	}
	writer.close();
}*/

void makeHeader()
{
	header = "";
	unordered_map<char, byteToken>::iterator it = byteTokens.begin();
	char nTokens = byteTokens.size();
	header += nTokens;
	for (it; it != byteTokens.end(); it++)
	{
		unsigned char byteToken, codeLength;
		byteToken = it->first;
		vector<unsigned char> code = codeStringToBytes(it->second.getCode());
		codeLength = (unsigned char)it->second.getCode().size();
		header += byteToken;
		header += codeLength;
		for (int j = 0; j < code.size(); j++)
		{
			header += code[j];
		}
	}
}

vector<unsigned char> codeStringToBytes(string code)
{
	vector<unsigned char> ret;
	unsigned char c = 0;
	int counter = 0;
	int codeSize = code.size();
	int codeIndex = 0;
	while (codeIndex < codeSize)
	{
		char codeBit = code.at(codeIndex);
		if (codeBit == '1')
			c = c | (unsigned char)1;
		c = c << 1;
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
		c = c << 1;
		counter++;
	}

	ret.push_back(c);
	return ret;
}