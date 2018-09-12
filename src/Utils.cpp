#include "Utils.h"
#include <iostream>


Utils::Utils() = default;

Utils::~Utils() = default;

int Utils::readNumber(int ceiling)
{
	int ret = 0;
	bool validString = false;
	while(!validString)
	{
		std::string temp;
		std::cout << "Please input a number [1-" << ceiling << "]: ";
		std::cin >> temp;

		if(stringIsNumber(temp))
		{
			ret = std::stoi(temp);
			if(ret >= 1 && ret <= ceiling)
				validString = true;
		}
		if(!validString)
			std::cout << "\nInvalid input\n";
	}
	std::cout << "\n\n";
	return ret;
}

bool Utils::stringIsNumber(std::string strToTest) {
	if(strToTest.empty())
		return false;
	for (char i : strToTest) {
		if(!std::isdigit(i))
			return false;
	}
	return true;
}


