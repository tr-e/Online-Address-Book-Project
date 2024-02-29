#include "addressBookType.h" //header file for addressBookType class
#include "utils.h" //For toLowerCase function
#include <iostream>  // To read/write to console 
#include <string>    // for string class
#include <fstream>   // for file I/O
#include <sstream>   // stringstream
#include <limits>    // for numeric_limits
#include <vector>    // For vector, use in find functions
#include <algorithm> // For std::transform


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::cerr;
using std::vector;

//Initializes the addressBookType class
addressBookType::addressBookType() : maxLength(500), length(0) {}


/*
Creates entries in the addressBookType class

@param: string first, string last, int month, int day, int year, string address, string city, string state, int zip, string phone, string relation

Precondition: A valid filename is passed to the function

Postcondition: The addressBookType class is populated with entries
*/
void addressBookType::initEntry(string fileName) {
    //variables used to create a new entry
    string name, first, last, street, city, state, phoneNumber, relationship;
    int month, day, year, zip;

    ifstream inFile;
    inFile.open(fileName);


    //If the file does not exist, print an error message and exit the program
    if (!inFile) {
        cerr << "Error: Unable to open file " << fileName << endl;
        return;
    }


    //enters file and reads lines into variables that are later used to create a extPersonType object. 
    while (getline(inFile, name)) {

        stringstream ss(name);
        ss >> first >> last;

        inFile >> month >> day >> year;
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        getline(inFile, street);
        getline(inFile, city);
        getline(inFile, state);
        inFile >> zip;
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        getline(inFile, phoneNumber);
        getline(inFile, relationship);

        extPersonType person(first, last, month, day, year,
            street, city, state, zip, phoneNumber, trim(relationship));

        addEntry(person);
    }
    inFile.close();
    sortEntries();
}


/*
Adds new entries into an address book

Precondition: The length of the address book must be less than maxLength and a valid extPersonType object must be passed as a parameter

Postcondition: The new entry is added to the address book and the length is incremented
*/
void addressBookType::addEntry(extPersonType person) {
    if (length < maxLength) {
        addressList[length] = person;
        length++;
    }
    else {
        cout << "Address book is full" << endl;
    }
}


/*
  Searches for a person by last name

  Preconditions: The address book must be initialized and a valid last name must be passed as a parameter

  Postconditions: If the person is found, the person's information is printed, otherwise an error message is printed

  Utilizes linear search --> short list --> O(n)
*/
void addressBookType::findPerson(string lastName) {
    vector<extPersonType> foundPersons;

    for (int i = 0; i < length; i++) {
        if (toLowerCase(addressList[i].getLastName()) == toLowerCase(lastName)) {
            foundPersons.push_back(addressList[i]);
        }
    }
    //print out found person(s)
    for (const auto& person : foundPersons) {
        person.print();
        cout << endl;
    }

    if (foundPersons.empty()) {
        cout << "No person found" << endl;
    }

}


/*
  Searches for a person by birth month

  Preconditions: The address book must be initialized and a valid integer must be passed as a parameter

  Postconditions: The person(s) with the same birth month are printed out

  Utilizes linear search --> small list --> O(n); could optimize with binary search
*/
void addressBookType::findBirthdays(int month) {
    vector<extPersonType> foundBirthdays;

    for (int i = 0; i < length; i++) {
        if (addressList[i].getBirthMonth() == month) {
            foundBirthdays.push_back(addressList[i]);
        }
    }

    for (const auto& person : foundBirthdays) {
        person.print();
        cout << endl;
    }

    if (foundBirthdays.empty()) {
        cout << "No birthdays found" << endl;
    }
}


/*
Searches for a person by relationship

Preconditions: The address book must be initialized and a valid relationship must be passed as a parameter

Postconditions: The person(s) with the same relationship are printed out

Utilizes linear search algo --> small list --> O(n)
*/
void addressBookType::findRelations(string relationship) {
    vector<extPersonType> foundRelations;

    for (int i = 0; i < length; i++) {
        if (toLowerCase(addressList[i].getRelationship()) == toLowerCase(relationship)) {
            foundRelations.push_back(addressList[i]);
        }
    }


    for (const auto& person : foundRelations) {
        person.print();
        cout << endl;
    }


    if (foundRelations.empty()) {
        cout << "No relations found" << endl;
    }
}


/*
Sorts the address book by last name

Preconditions: The address book must be initialized

Postconditions: The address book is sorted by last name

Utilizes insertion sort algo --> 0(n^2)
*/
void addressBookType::sortEntries() {
    bool placeFound;
    int index;
    int current = 1;

    while (current < length) {
        index = current;
        placeFound = false;
        while (index > 0 && !placeFound) {
            if (addressList[index] < addressList[index - 1]) {
                extPersonType temp = addressList[index];
                addressList[index] = addressList[index - 1];
                addressList[index - 1] = temp;
                index--;
            }
            else {
                placeFound = true;
            }
        }
        current++;
    }
}


/*
Prints the address book

Preconditions: The address book must be initialized

Postconditions: The address book is printed out
*/
void addressBookType::print() const {
    for (int i = 0; i < length; i++) {
        addressList[i].print();
        cout << endl;
    }
}
