#include "dateType.h"
#include <iostream>

dateType::dateType(int d, int m, int y)
{
	setDate(d, m, y); // Valadates and sets the date.
}

void dateType::setDate(int d, int m, int y)
{
	// Checks Year
	if (y < 1900)
		dYear = 1900;
	else
		dYear = y;

	// Checks month
	if (m < 1 || m > 12)
		dMonth = 1;
	else
		dMonth = m;


	// Checks day
	int lastDayOfMonth = daysInMonth(dMonth, dYear);
	if (d < 1 || d > lastDayOfMonth)
		dDay = 1;
	else
		dDay = d;
}

int dateType::getDay() const { return dDay; }
int dateType::getMonth() const { return dMonth; }
int dateType::getYear() const { return dYear; }
void dateType::print() const { std:: cout << dMonth << "/" << dDay << "/" << dYear << std::endl; }
bool dateType::isLeapYear(int year) const { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }
int dateType:: daysInMonth(int month, int year) const 
{
	switch (month)
	{
		case 2:
			if (isLeapYear(year))
				return 29;
			else
				return 28;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		default:
			return 31;


	}
}

