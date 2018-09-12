#include "ByteToken.h"


ByteToken::ByteToken() = default;

ByteToken::ByteToken(char key)
{
	this->key = key;
}

ByteToken::~ByteToken() = default;

void ByteToken::increaseCount()
{
	this->count++;
}

void ByteToken::setCode(const std::string &code)
{
	this->code = code;
}

char ByteToken::getKey()
{
	return this->key;
}

long ByteToken::getCount()
{
	return this->count;
}

std::string ByteToken::getCode()
{
	return this->code;
}
