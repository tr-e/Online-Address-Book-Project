#pragma once 
#include "addressBookType.h"

class Menu {

public:

	/*
		Runs the program 
		
		Precondition: None 

		PostCondition: The program is run 
	*/
	void run();


	/*
	  Prints a welcome message

	  Precondition: None

	  Postcondition: A welcome message is printed out
	*/
	void welcome();


private:

	/*
	  Displays the menu to the user and prompts them to select an option

	  Precondition: None

	  Postcondition: The user is prompted to select an option from the menu
	*/
	void displayMenu();


	/*
	  Processes user selections

	  Precondition: The user must select a valid option from the menu

	  Postcondition: The user's selection is processed and the appropriate function is ran
	*/
	void processSelection(addressBookType&);
};