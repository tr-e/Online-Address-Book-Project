#pragma once
#include <string>

using std::string;
class personType
{
public:
	//constructor
	personType(string firstName = "", string lastName = "");

	//setters and getters
	virtual void setFirstName(string firstName);
	virtual void setLastName(string lastName);
	virtual string getFirstName() const { return firstName; }
	virtual string getLastName() const { return lastName; }

	//print 
virtual void print() const;
private: 
	string firstName; 
	string lastName;
};

