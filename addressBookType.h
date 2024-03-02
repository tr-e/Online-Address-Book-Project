#pragma once
#include "extPersonType.h"
#include <string>

using std::string;

class addressBookType
{
public:

    //constructor 
    addressBookType();


    /*
        Creates entries in the addressBookType class

        @param: string first, string last, int month, int day, int year, string address, string city, string state, int zip, string phone, string relation

        Precondition: A valid filename is passed to the function

        Postcondition: The addressBookType class is populated with entries
    */
    void initEntry(string); 

    
    /*
        Adds new entries into an address book

        Precondition: The length of the address book must be less than maxLength and a valid extPersonType object must be passed as a parameter

        Postcondition: The new entry is added to the address book and the length is incremented
    */
    void addEntry(extPersonType); 


    /*
        Searches for a person by last name

        Preconditions: The address book must be initialized and a valid last name must be passed as a parameter

        Postconditions: If the person is found, the person's information is printed, otherwise an error message is printed

        Utilizes linear search --> short list --> O(n)
    */
    void findPerson(string); 

    /*
        Searches for a person by birth month

        Preconditions: The address book must be initialized and a valid integer must be passed as a parameter

        Postconditions: The person(s) with the same birth month are printed out

         Utilizes linear search --> small list --> O(n); could optimize with binary search
    */
    void findBirthdays(int); 


    /*
        Searches for a person by relationship

        Preconditions: The address book must be initialized and a valid relationship must be passed as a parameter

        Postconditions: The person(s) with the same relationship are printed out

        Utilizes linear search algo --> small list --> O(n)
    */
    void findRelations(string);
    
    /*
        Sorts the address book by last name

        Preconditions: The address book must be initialized

        Postconditions: The address book is sorted by last name

        Utilizes insertion sort algo --> 0(n^2)
    */
    void sortEntries();
    
    /*
        Prints the address book

        Preconditions: The address book must be initialized

        Postconditions: The address book is printed out
    */
    void print(void) const;



private:
    extPersonType addressList[500];
    int length;
    int maxLength;
};


