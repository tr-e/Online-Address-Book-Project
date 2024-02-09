#pragma once
class dateType
{
public:
	dateType(int = 1, int = 1, int = 1900);
	
	void setDate(int, int, int) {};
	
	int getDay() const { return dDay; }
	int getMonth() const { return dMonth; }
	int getYear() const { return dYear; }

	bool isLeapYear(int);
	
	void print() const {};

private: 
	int dDay;
	int dMonth;
	int dYear;
};

