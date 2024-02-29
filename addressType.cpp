
#include "addressType.h"
#include <iostream>
#include <string>
#include <iomanip> 

using std::string;
using std::cout;
using std::endl;
using std::setw;
using std::left;

//default constructor
addressType::addressType() : streetAddress(""), city(""), state("XX"), zip(10000) {}

//constructor
addressType::addressType(string newStreetAddress, string newCity, string newState, int newZip) :
	streetAddress(newStreetAddress), city(newCity), state(newState), zip(newZip) {}


/*
  Sets the street address for the addressType object

  Precondition: A valid street address must be passed as a parameter

  Postcondition: The street address is set for the addressType object
*/
void addressType::setAddress(string address) { this->streetAddress = address; }


/*
  Sets the city for the addressType object

  Precondition: A valid city must be passed as a parameter

  Postcondition: The city is set for the addressType object
*/
void addressType::setCity(string city) { this->city = city; }


/*
  Sets the state for the addressType object

  Precondition: A valid state must be passed as a parameter

  Postcondition: The state is set for the addressType object
*/
void addressType::setState(string state) { this->state = state; this->state = (state.length() == 2) ? state : "XX"; }


/*
  Sets the zip code for the addressType object

  Precondition: A valid zip code must be passed as a parameter

  Postcondition: The zip code is set for the addressType object
*/
void addressType::setZipcode(int zip) { this->zip = zip; this->zip = (zip > 0 && zip < 99999) ? zip : 00000; }


/*
  Prints the addressType object

  Precondition: The addressType object must be initialized

  Postcondition: The addressType object is printed out
*/
void addressType::print() const {
	cout << left << setw(3) << "Address: " << streetAddress << endl;
	cout << left << setw(3) << "City: " << city << endl;
	cout << left << setw(3) << "State: " << state << endl;
	cout << left << setw(3) << "Zipcode: " << zip;
}