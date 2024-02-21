#include "extPersonType.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//default constructor
extPersonType::extPersonType(string first, string last, int month, int day, int year, string street, string city, string state, int zip, string phoneNumber, string relationship) : 
personType(first, last), birthdate(month, day, year), address(street, city, state, zip), phoneNumber(phoneNumber), relationship(relationship) {}

//Setters for extPersonType functions 
void extPersonType::setPhoneNumber(string phone) {
	this->phoneNumber = phone;
	}

void extPersonType::setRelationship(string relation) {
	if (relation == "Friend" || relation == "Business" || relation == "Family") {
		this->relationship = relation;
	}
	else {
		this->relationship = "";
	}
}

//Print function utilizes member function of imported classes
void extPersonType::print() const {
	personType::print();
	cout << endl;
	birthdate.print();
	address.print();
	cout << phoneNumber << endl;
	cout << relationship << endl;
}
