#pragma once
#include <iostream>

class dateType
{
public:
	//Default constructor 
	dateType(int = 1, int = 1, int = 1900);

	//PreCondition: 0 <= day <= 31, 0 <= month <= 12, 0 <= year <= 9999
	void setDate(int, int, int);
	//PostCondition: dDay = day, dMonth = month, dYear = year

	//PreCondition : 0 <= day <= 31, 0 <= month <= 12, 0 <= year <= 9999
	int getDay() const { return dDay; }
	int getMonth() const { return dMonth; }
	int getYear() const { return dYear; }
	// PostCondition: returns dDay, dMonth, dYear


	//Precondtion: 0 <= day <= 31, 0 <= month <= 12, 0 <= year <= 9999
	bool isLeapYear(int);
	//PostCondition: returns true if year is a leap year, false otherwise


	//PreCondition: 0 <= day <= 31, 0 <= month <= 12, 0 <= year <= 9999
	void print() const;
	//PostCondition: prints dDay, dMonth, dYear

private:
	int dDay;
	int dMonth;
	int dYear;
};
