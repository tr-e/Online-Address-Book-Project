#include "dateType.h"
#include <iostream>
#include <string>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::setw;


//default constructor
dateType::dateType(int month, int day, int year) : dMonth(month), dDay(day), dYear(year) {}


/*
  Finds if a year is a leap year

  Precondition: A valid year must be passed as a parameter

  Postcondition: If the year is a leap year, true is returned, otherwise false is returned
*/
bool dateType::isLeapYear(int dYear) {
    if (dYear % 4 == 0) {
        if (dYear % 100 == 0) {
            if (dYear % 400 == 0) {
                return true;
            }
            else { return false; }
        }
        else { return true; }
    }
    else { return false; }
    return false;
}


/*
  Set to defaults if invalid

  PreCondiiton: A valid month, day, and year must be passed as parameters, otherwise sets to defaults

  Postcondition: Sets the date to defaults if invalid, otherwise sets the date to the passed parameters
*/
void dateType::setDate(int dMonth, int dDay, int dYear) {
    //checks if the month is valid 
    if (dMonth < 1 || dMonth > 12) {
        dMonth = 1;
        dDay = 1;
        dYear = 1900;
    }

    //Checks if day is valid 
    if (dDay < 1 || dDay > 31) {
        dDay = 1;
    }


    //Used for the month of february
    if (dMonth == 2 && dDay > 28) {
        if (isLeapYear(dYear)) {
            if (dDay > 29) {
                dMonth = 1;
                dDay = 1;
                dYear = 1900;
            }
        }
        else {
            dMonth = 1;
            dDay = 1;
            dYear = 1900;
        }
    }


    //Used to determine if the day is valid for the month
    if (dMonth == 4 || dMonth == 6 || dMonth == 9 || dMonth == 11) {
        if (dDay > 30) {

            dMonth = 1;
            dDay = 1;
            dYear = 1900;
        }
    }


    //Used to determine if year is valid
    if (dYear < 1900) {
        dMonth = 1;
        dDay = 1;
        dYear = 1900;
    }
    this->dMonth = dMonth;
    this->dDay = dDay;
    this->dYear = dYear;
}


/*
  Prints the date in the format mm/dd/yyyy

  Precondition: The date must be initialized

  Postcondition: The date is printed out in the format mm/dd/yy
*/
void dateType::print() const {
    cout << setw(3) << "DOB: " << dMonth << "/" << dDay << "/" << dYear;
}