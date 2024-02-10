#include "dateType.h"
#include <iostream>
#include <string>

using std::string;
using std::cout; 
using std::endl;

dateType::dateType(int month, int day, int year) : dMonth(month), dDay(day), dYear(year) {}


bool dateType::isLeapYear(int dYear) {
	if (dYear % 4 == 0) {
		if (dYear % 100 == 0) {
			if (dYear % 400 == 0) {
				return true;
			} else { return false; }
		} else { return true;}
	} else { return false;}
return false;
}

//Set to defaults if invalid
void dateType::setDate(int dMonth, int dDay, int dYear) {
	if (dMonth < 1 || dMonth > 12) {
		dMonth = 1;
		dDay = 1;
		dYear = 1900;
	}
	if (dDay < 1 || dDay > 31) {
		dDay = 1;
	}
	if (dMonth == 2 && dDay > 28) {
		if (isLeapYear(dYear)) {
			if (dDay > 29) {
				dMonth = 1;
				dDay = 1;
				dYear = 1900;
				//Used if defaults were mutating the day and not whole date
				//dDay = 29;
			}
		} else {
			dMonth = 1;
			dDay = 1;
			dYear = 1900;
			//Used if defaults were mutating the day and not whole date
			//dDay = 28;
		}
	}
	if (dMonth == 4 || dMonth == 6 || dMonth == 9 || dMonth == 11) {
		if (dDay > 30) {
			//Used if defaults were mutating the day and not whole date
			dMonth = 1;
			dDay = 1;
			dYear = 1900;	
		}
	}
	if (dYear < 1900) {
		dMonth = 1;
		dDay = 1;
		dYear = 1900;
	}
	this->dMonth = dMonth;
	this->dDay = dDay;
	this->dYear = dYear;
}


void dateType::print() const {
	cout << dMonth << "-" << dDay << "-" << dYear << endl;
}