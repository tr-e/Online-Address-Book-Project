#pragma once
#include <string>

class addressType
{
public: 
	//Default Constructor
	addressType();

	//Constructor with parameters
	addressType(std::string, std::string, std::string, int);

	void setAddress(std::string address);
	void setCity(std::string city);
	void setState(std::string state);
	void setZipcode(int zipCode);

	std::string getAddress() const { return streetAddress; }
	std::string getCity() const { return city; }
	std::string getState() const { return state; }
	int getZipcode() const { return zip; }
	void print() const;

private:
	std::string streetAddress;
	std::string city;
	std::string state;
	int zip;
};

