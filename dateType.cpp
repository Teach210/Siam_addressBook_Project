#include "dateType.h"
#include <iostream>

dateType::dateType() {
    setDate(1, 1, 1900); // Default date: January 1, 1900
}

dateType::dateType(int m, int d, int y) {
    setDate(m, d, y); // Sets the date with provided parameters
}

void dateType::setDate(int m, int d, int y) {
    // Check Year
    if (y < 1900) {
        dYear = 1900;
        dMonth = 1;
        dDay = 1;
        //std::cout << "Month =" << dMonth << " ";
        //std::cout << "Day =" << dDay << " ";
        std::cout << "Date invalid, setting to 1/1/1900" << std::endl;
        return; // exists the function
    }
    else {
        dYear = y;
    }

    // Check Month
    if (m < 1 || m > 12) {
        dYear = 1900;
        dMonth = 1;
        dDay = 1;
        std::cout << "Date invalid, setting to 1/1/1900" << std::endl;
        return;
    }
    else {
        dMonth = m;
    }

    // Check Day
    int lastDayOfMonth = daysInMonth(dMonth, dYear);
    if (d < 1 || d > lastDayOfMonth) {
        dYear = 1900;
        dMonth = 1;
        dDay = 1;
        std::cout << "Date invalid, setting to 1/1/1900" << std::endl;
        return;
    }
    else {
        dDay = d;
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