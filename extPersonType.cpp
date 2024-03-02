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


bool extPersonType::operator<(const extPersonType& right) const {
    return this->getLastName() < right.getLastName();
}


void extPersonType::setPhoneNumber(string phone) {
    this->phoneNumber = phone;
}


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


void extPersonType::print() const {
    personType::print();
    birthdate.print();
    cout << endl;
    address.print();
    cout << endl;
    cout << std::setw(3) << "Phone Number: " << phoneNumber << endl;
    cout << std::setw(3) << "Relation: " << relationship << endl;
}
