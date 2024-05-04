#include "dateType.h"
#include <iostream>

dateType::dateType() {
    setDate(1, 1, 1900); // Default date: January 1, 1900
}

dateType::dateType(int m, int d, int y) {
    setDate(m, d, y); // Sets the date with provided parameters
}

void dateType::setDate(int m, int d, int y) {
    bool validDate = true;

    // Print input values for debugging

    // Check Year
    if (y < 1900) {
        validDate = false;
        dYear = 1900;
        std::cout << "Invalid Year" << std::endl; // Debugging output
    }
    else {
        dYear = y;
    }

    // Check Month
    if (m < 1 || m > 12) {
        validDate = false;
        dMonth = 1;
        std::cout << "Invalid Month" << std::endl; // Debugging output
    }
    else {
        dMonth = m;
    }

    // Check Day
    int lastDayOfMonth = daysInMonth(dMonth, dYear);
    if (d < 1 || d > lastDayOfMonth) {
        validDate = false;
        dDay = 1;
        std::cout << "Invalid Day" << std::endl; // Debugging output
    }
    else {
        dDay = d;
    }

    // Print message for invalid date
    if (!validDate) {
        std::cout << "Date invalid, setting to " << dMonth << "/" << dDay << "/" << dYear << std::endl;
    }
}

void dateType::print() const {
    std::cout << dMonth << "-" << dDay << "-" << dYear << std::endl;
}

int dateType::getDay() const {
    return dDay;
}

int dateType::getMonth() const {
    return dMonth;
}

int dateType::getYear() const {
    return dYear;
}

bool dateType::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dateType::daysInMonth(int month, int year) const
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