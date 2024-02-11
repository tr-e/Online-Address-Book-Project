#pragma once
#include <string>

class addressType
{
public: 
	//Default Constructor
	addressType();

	//Constructor with parameters
	addressType(std::string, std::string, std::string, int);

	//Setters and Getters 
	//Precondition: The address, city, state, and zipCode have been initialized
	void setAddress(std::string address);
	void setCity(std::string city);
	void setState(std::string state);
	void setZipcode(int zipCode);

	std::string getAddress() const { return streetAddress; }
	std::string getCity() const { return city; }
	std::string getState() const { return state; }
	int getZipcode() const { return zip; }
	//Postcondition: The address, city, state, and zipCode have been returned
	//End of Setters and Getters
	
	//Precondition: The address, city, state, and zipCode have been initialized
	void print() const;
	//Postcondition: The address, city, state, and zipCode have been printed

private:
	std::string streetAddress;
	std::string city;
	std::string state;
	int zip;
};

