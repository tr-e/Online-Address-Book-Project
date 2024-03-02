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


void addressBookType::addEntry(extPersonType person) {
    if (length < maxLength) {
        addressList[length] = person;
        length++;
    }
    else {
        cout << "Address book is full" << endl;
    }
}


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


void addressBookType::print() const {
    for (int i = 0; i < length; i++) {
        addressList[i].print();
        cout << endl;
    }
}
