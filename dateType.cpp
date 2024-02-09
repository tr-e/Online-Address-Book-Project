#include "dateType.h"
#include <iostream>
#include <string>

using std::string;
using std::cout; 
using std::endl;

dateType::dateType(int dMonth, int dDay, int dYeah) {
	setDate(dMonth, dDay, dYeah);
}

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

