#pragma once
#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>

using std::string;

class extPersonType : public personType 
{
	public:
		//constructor
		extPersonType(string first = "", string last = "", int month = 1, int day = 1, int year = 1900, 
		string street = "", string city = "", string state = "XX", int zip = 10000, string phoneNumber = "", string relationship = "");

		//setters and getters
		void setPhoneNumber(string phoneNumber);
		void setRelationship(string relationship);
		
		string getPhoneNumber() const { return phoneNumber; }
		string getRelationship() const { return relationship; }
		int getBirthMonth() const { return birthdate.getMonth(); }

		// print information of person  
		void print() const; 

	private: 
		addressType address;
		dateType birthdate;
		string phoneNumber;
		string relationship;

};

