#pragma once
#include <iostream>


class dateType {
public:
    dateType(); // Default constructor
    dateType(int m, int d, int y); // Constructor with parameters

    void setDate(int m, int d, int y);
    void print() const;

    int getDay() const;   // Getter function for day
    int getMonth() const; // Getter function for month
    int getYear() const;  // Getter function for year

private:
    int dDay;
    int dMonth;
    int dYear;
    bool isLeapYear(int year) const;
    int daysInMonth(int month, int year) const;
};

