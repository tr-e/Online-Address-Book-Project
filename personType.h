#pragma once
#include <string>

using std::string;
class personType
{
public:

	//constructor
	personType(string firstName = "", string lastName = "");

	//setters and getters
	/*
	  Sets the first name for the personType object

	  Precondition: A valid string must be passed as a parameter

	  Postcondition: The first name is set for the personType object
	*/
	virtual void setFirstName(string firstName);

	/*
	  Sets the Last name for the personType object

	  Precondition: A valid string must be passed as a parameter

	  Postcondition: The last name is set for the personType object
	*/
	virtual void setLastName(string lastName);

	//Precondition: None 
	virtual string getFirstName() const { return firstName; }
	virtual string getLastName() const { return lastName; }
	//PostCondition: returns requested type


	/*
	Prints the personType object

	Precondition : The personType object must be initialized

	Postcondition : The personType object is printed out
	*/
	void print() const;

private:
	string firstName;
	string lastName;
};


