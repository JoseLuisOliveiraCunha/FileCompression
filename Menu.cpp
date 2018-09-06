#include <iostream>

#include "Menu.h"
#include "Utils.h"


Menu::Menu()
{
	state = MAIN;
}

Menu::~Menu()
{
}

void Menu::menuStateManager()
{
	switch (state)
	{
		case MAIN:
			mainMenu();
			break;
		case HUFFMAN:
			huffman();
			break;
		default:

			break;
	}
}

void Menu::mainMenu()
{
	std::cout << "File compression algorithms\n\n";
}

void Menu::huffman()
{
	std::cout << "Huffman compression\n\n"
		<< "1. Compress file\n"
		<< "2. Decompress file\n"
		<< "3. Back to main menu\n";
	
}

void Menu::about()
{

}
