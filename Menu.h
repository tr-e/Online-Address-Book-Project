#pragma once 
#include "addressBookType.h"

class Menu {

public:

	//Runs the menu 
	void run();

	//welcomes the user 
	void welcome();


private:

	//Displays menu options to user
	void displayMenu();

	//Process user selection 
	void processSelection(addressBookType&);
};