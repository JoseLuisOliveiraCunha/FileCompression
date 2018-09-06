#pragma once

#include <string>

class ByteToken
{
private:
	char key = 'a';
	long count = 1;
	std::string code = "";

public:
	ByteToken() {};
	ByteToken(char key);
	~ByteToken();
	void increaseCount();
	void setCode(std::string code);
	char getKey();
	long getCount();
	std::string getCode();
};

