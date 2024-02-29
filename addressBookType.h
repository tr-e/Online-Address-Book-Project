#pragma once
#include "extPersonType.h"
#include <string>

using std::string;

class addressBookType
{
public:
    //constructor 
    addressBookType();
    //functions
    void initEntry(string); //reads entries from file -> creates extPersonType object 

    void addEntry(extPersonType); //adds extPersonType object to addressList 

    void findPerson(string); //searches based on last name -> returns all entry info
    void findBirthdays(int); //searches based on month(int) -> returns entries with same birth month
    void findRelations(string); //searches based on relationship -> returns names associated with relationship

    void sortEntries(); //insertion sort -> sorts by last name 
    void print(void) const;



private:
    extPersonType addressList[500];
    int length;
    int maxLength;
};


