#pragma once

#include <string>

class Utils
{
public:
	Utils();
	~Utils();
	static int readNumber(int ceiling);
	static bool stringIsNumber(std::string strToTest);
};

