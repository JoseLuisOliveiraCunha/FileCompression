#include <iostream>

#include "Menu.h"
#include "Utils.h"
#include "Huffman.h"


Menu::Menu() = default;

Menu::~Menu() = default;

void Menu::menuStateManager()
{
	while(appRunning)
	{
		switch (state)
		{
			case MAIN:
				mainMenu();
				break;
			case HUFFMAN:
				huffman();
				break;
            case ABOUT:
                about();
                break;
			default:

				break;
		}
	}

}

void Menu::mainMenu()
{
	std::cout << "File compression algorithms\n\n"
			<< "1. Huffman compression\n"
			<< "2. About\n"
			<< "3. Quit\n";
	int choice = Utils::readNumber(MENU_MAIN_CHOICES);
	switch(choice)
	{
		case 1:
			state = HUFFMAN;
			break;
		case 2:
			state = ABOUT;
			break;
		case 3:
			appRunning = false;
			break;
		default:
			break;
	}
}

void Menu::huffman()
{
	std::cout << "Huffman compression\n\n"
		<< "1. Compress file\n"
		<< "2. Decompress file (UNAVAILABLE)\n"
		<< "3. Back to main menu\n";
	int choice = Utils::readNumber(MENU_HUFFMAN_CHOICES);
	switch(choice)
	{
		case 1:
		{
			Huffman h = Huffman();
			state = HUFFMAN;
			break;
		}
		case 2:
		{
			state = HUFFMAN;
			break;
		}
		case 3:
			state = MAIN;
			break;
		default:
			break;
	}
}

void Menu::about()
{
	std::cout << "About\n\n"
			  << "1. Back to main menu\n";
    int choice = Utils::readNumber(MENU_HUFFMAN_CHOICES);
    switch(choice)
    {
        case 1:
            state = MAIN;
            break;
    	default:
    		break;
    }
}
