#include "personType.h"
#include <iostream>
#include <iomanip>


using std::string;
using std::cout;
using std::endl;
using std::setw;

//default constructor
personType::personType(string first, string last) : firstName(first), lastName(last) {}

void personType::setFirstName(string first) { firstName = first; }

void personType::setLastName(string last) { lastName = last; }

void personType::print() const {
	cout << setw(3) << "Name: " << firstName << " " << lastName << endl;
}