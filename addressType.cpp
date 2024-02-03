
#include "addressType.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

addressType::addressType() : streetAddress(""), city(""), state("XX"), zip(10000) {}
addressType::addressType(string newStreetAddress, string newCity, string newState, int newZip) :
	streetAddress(newStreetAddress), city(newCity), state(newState), zip(newZip) {}

void addressType::setAddress(string address) { this->streetAddress = address; }
void addressType::setCity(string city) { this->city = city; }
void addressType::setState(string state) { this->state = state; this -> state = (state.length() == 2) ? state : "XX"; }
void addressType::setZipcode(int zip) { this->zip = zip; this -> zip = (zip > 0 && zip < 99999) ? zip : 00000; }
//string addressType::getAddress() const { return streetAddress; }
//string addressType::getCity() const { return city; }
//string addressType::getState() const { return state; }
//int addressType::getZipcode() const { return zip; }
void addressType::print() const {
	cout << streetAddress << endl;
	cout << city << ", " << state << " " << zip << endl;

}