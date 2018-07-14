#include "byteToken.h"

byteToken::byteToken(char key)
{
	this->key = key;
}


byteToken::~byteToken()
{

}

void byteToken::increaseCount()
{
	this->count++;
}

void byteToken::setCode(string code)
{
	this->code = code;
}

char byteToken::getKey()
{
	return this->key;
}

long byteToken::getCount()
{
	return this->count;
}

string byteToken::getCode()
{
	return this->code;
}
