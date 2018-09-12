#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <unordered_map>

#include "ByteToken.h"
#include "Node.h"
#include "Constants.h"

class Huffman
{
private:
	std::vector<char> readData;
	std::vector<std::string> compressedData;
	std::unordered_map<char, ByteToken> byteTokens;
	std::priority_queue<Node> huffman;
	std::vector<Node *> storedNodes;
	std::string filepath;
	std::string header;

public:
	Huffman();
	~Huffman();
	std::string readFile();
	void analyzeData();
	void huffmanTree();
	void extractCodes(Node n, std::string code);
	void compressFile();
	void makeHeader();
	std::vector<unsigned char> codeStringToBytes(std::string code);
	void outputCompressedFile();
};

