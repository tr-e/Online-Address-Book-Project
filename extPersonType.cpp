#include "extPersonType.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector> 
#include <algorithm> 


using std::cout;
using std::endl;
using std::string;
using std::vector;


//default constructor 
extPersonType::extPersonType(string first, string last, int month, int day, int year, string street, string city, string state, int zip, string phoneNumber, string relationship) : personType(first, last), birthdate(month, day, year), address(street, city, state, zip), phoneNumber(phoneNumber), relationship(relationship) {}


/*
  Used to setup comparison operators for extPersonType objects
  Primarily used for sorting the address book by last name

  Precondition: A valid extPersonType object must be passed as a parameter

  Postcondition: The comparison operators are setup for extPersonType objects
*/
bool extPersonType::operator<(const extPersonType& right) const {
    return this->getLastName() < right.getLastName();
}


/*
  Sets phoneNumber for extPersonType object

  Precondition: A valid phone number must be passed as a parameter

  Postcondition: The phone number is set for the extPersonType object
*/
void extPersonType::setPhoneNumber(string phone) {
    this->phoneNumber = phone;
}


/*
  Sets relationship for extPersonType object

  Precondition: A valid relationship must be passed as a parameter

  Postcondition: The relationship is set for the extPersonType object

  Using vector for ease of use
*/
void extPersonType::setRelationship(string relationship) {
    relationship = toLowerCase(relationship);
    vector <string> validRelationships = { "friend", "family", "business" };

    auto found = std::find(validRelationships.begin(), validRelationships.end(), relationship);

    if (found != validRelationships.end()) {
        this->relationship = relationship;
    }
    else {
        cout << "Invalid relationship" << endl;
    }
}


/*
  Prints the extPersonType object

  Precondition: The extPersonType object must be initialized

  Postcondition: The extPersonType object is printed out
*/
void extPersonType::print() const {
    personType::print();
    birthdate.print();
    cout << endl;
    address.print();
    cout << endl;
    cout << std::setw(3) << "Phone Number: " << phoneNumber << endl;
    cout << std::setw(3) << "Relation: " << relationship << endl;
}
