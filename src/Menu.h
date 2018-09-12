#pragma once

#include "Constants.h"

/**
 * outputs menus and allows their navigation
 */
class Menu
{

private:
	menuState state = MAIN;
	bool appRunning = true;

public:
    /**
     * defines menu state to MAIN_MENU
     */
	Menu();


	~Menu();

	/**
	 *
	 */
	void menuStateManager();

	/**
	 *
	 */
	void mainMenu();

	/**
	 *
	 */
	void huffman();

	/**
	 *
	 */
	void about();
};

