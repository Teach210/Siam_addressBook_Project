#pragma once
#include <iostream>

class dateType
{
private:
	int dDay = 1;
	int dMonth = 1;
	int dYear = 1900;

public:
	// Constructor//
	dateType(int d, int m, int y);

	// Setter
	void setDate(int d, int m, int y);

	// Getter
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	// Other

	void print() const;
	bool isLeapYear(int Year) const;
	int daysInMonth(int month, int year) const;


};

