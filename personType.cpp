#include "personType.h"
#include <iostream>
#include <iomanip>


using std::string;
using std::cout;
using std::endl;
using std::setw;

//default constructor
personType::personType(string first, string last) : firstName(first), lastName(last) {}

/*
  Sets the first name for the personType object

  Precondition: A valid string must be passed as a parameter

  Postcondition: The first name is set for the personType object
*/
void personType::setFirstName(string first) { firstName = first; }

/*
  Sets the Last name for the personType object

  Precondition: A valid string must be passed as a parameter

  Postcondition: The last name is set for the personType object
*/
void personType::setLastName(string last) { lastName = last; }

/*
  Prints the personType object

  Precondition: The personType object must be initialized

  Postcondition: The personType object is printed out
*/
void personType::print() const {
	cout << setw(3) << "Name: " << firstName << " " << lastName << endl;
}