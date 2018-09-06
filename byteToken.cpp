#include "ByteToken.h"


ByteToken::ByteToken(char key)
{
	this->key = key;
}

ByteToken::~ByteToken()
{

}

void ByteToken::increaseCount()
{
	this->count++;
}

void ByteToken::setCode(std::string code)
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
