// derivation of personType class
#pragma once
#include "addressType.h"
#include "dateType.h"
#include "personType.h"
#include <string>

using std::string;

class extPersonType : public personType {
public:
    // constructor
    extPersonType(string first = "", string last = "", int month = 1, int day = 1,
        int year = 1900, string street = "", string city = "",
        string state = "XX", int zip = 10000, string phoneNumber = "",
        string relationship = "");

    // operator function for comparison

    /*
      Used to setup comparison operators for extPersonType objects
      Primarily used for sorting the address book by last name

      Precondition: A valid extPersonType object must be passed as a parameter

      Postcondition: The comparison operators are setup for extPersonType objects
    */
    bool operator<(const extPersonType& right) const;

    // setters and getters

    /*
      Sets phoneNumber for extPersonType object

      Precondition: A valid phone number must be passed as a parameter

      Postcondition: The phone number is set for the extPersonType object
    */
    void setPhoneNumber(string phoneNumber);

    /*
      Sets relationship for extPersonType object

      Precondition: A valid relationship must be passed as a parameter

      Postcondition: The relationship is set for the extPersonType object

      Using vector for ease of use
    */
    void setRelationship(string relationship);
   
    //Precondition(s): None
    string getPhoneNumber() const { return phoneNumber; }
    string getRelationship() const { return relationship; }
    int getBirthMonth() const { return birthdate.getMonth(); }
    //Postcondition(s): Returns requested information
    
    
    // print information of person

    /*
      Prints the extPersonType object

      Precondition: The extPersonType object must be initialized

      Postcondition: The extPersonType object is printed out
    */
    void print() const;

private:
    addressType address;
    dateType birthdate;
    string phoneNumber;
    string relationship;
};
