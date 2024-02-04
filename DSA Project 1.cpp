#include "addressType.h"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

int main() {
	cout << "Testing default constructor ... " << endl;
	addressType defAddress;
	defAddress.print();
	cout << endl;
	cout << "Testing constructor with parameters ... " << endl;
	addressType address("123 South Street", "Newport News", "VA", 23664);
	address.print();
	cout << endl;
	cout << "Testing invalid state (Virginia)... " << endl; 
	address.setState("Virginia");
	address.print();
	cout << endl;
	cout << "Testing invalid Zipcode (55555555) ..." << endl;
	address.setZipcode(55555555);
	address.print();
	cout << endl;
	cout << "Testing valid address ..." << endl;
	address.setAddress("44 East Main Street");
	address.setCity("Hampton");
	address.setState("VA");
	address.setZipcode(23669);
	address.print();
	cout << endl;

}

//testing new user configuration with commit and push. 