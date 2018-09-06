#pragma once

#include "Constants.h"

class Menu
{

private:
	menuState state;

public:
	Menu();
	~Menu();
	void menuStateManager();
	void mainMenu();
	void huffman();
	void about();
};

