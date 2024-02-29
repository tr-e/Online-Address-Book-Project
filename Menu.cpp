#include "menu.h"
#include "addressBookType.h"
#include <iostream>

using std::cout;
using std::cin;
using std::string;


/*
  Prints a welcome message

  Precondition: None

  Postcondition: A welcome message is printed out
*/
void Menu::welcome() {
    std::cout << "welcome to the address book program" << std::endl;
    std::cout << "please select an option from the menu below" << std::endl;
    std::cout << std::endl;
}

/*
  Displays the menu to the user and prompts them to select an option

  Precondition: None

  Postcondition: The user is prompted to select an option from the menu
*/
void Menu::displayMenu() {
    //possible future functionality
    //std::cout << "1. Add a new entry" << std::endl;
    std::cout << "1. Find a person by last name" << std::endl;

    std::cout << "2. Find a person by birth month" << std::endl;

    std::cout << "3. Find a person by relationship" << std::endl;

    std::cout << "4. Exit Program" << std::endl;

};

/*
  Processes user selections

  Precondition: The user must select a valid option from the menu

  Postcondition: The user's selection is processed and the appropriate function is ran
*/
void Menu::processSelection(addressBookType& addressBook) {
    bool exit = false; //flag 

    //Runs program selection loop
    do {
        displayMenu();
        string inputString;
        int inputInt;
        int choice;
        cin >> choice;
        cout << std::endl;
        switch (choice) {
        case 1:
            cout << "Enter the last name: ";
            cin >> inputString;
            addressBook.findPerson(inputString);
            break;
        case 2:
            cout << "Enter the birth month: ";
            cin >> inputInt;
            addressBook.findBirthdays(inputInt);
            break;
        case 3:
            cout << "Enter the relationship: ";
            cin >> inputString;
            addressBook.findRelations(inputString);
            break;
        case 4:
            exit = true;
            break;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (!exit);
};


/*
  Runs the program

  Precondition: None

  PostCondition: The program is run
*/
void Menu::run() {
    addressBookType addressBook;
    addressBook.initEntry("Online Address Book Data.txt");
    //utilize case statements
    processSelection(addressBook);  //process selection
};