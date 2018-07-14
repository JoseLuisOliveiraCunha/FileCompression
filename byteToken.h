#pragma once

#include <string>

using namespace std;

class byteToken
{
private:
	char key = 'a';
	long count = 1;
	string code = "";

public:
	byteToken() {};
	byteToken(char key);
	~byteToken();
	void increaseCount();
	void setCode(string code);
	char getKey();
	long getCount();
	string getCode();
};

