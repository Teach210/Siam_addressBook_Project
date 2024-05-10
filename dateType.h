#pragma once
#include <iostream>


class dateType {
public:
    // Default constructor
    // Precondition: None
    // Postcondition: Initializes the dateType object with default values for month,
    dateType(); 
    // Constructor with parameters
    // Precondition: 
    //   - m should be a valid month (1-12).
    //   - d should be a valid day corresponding to the month and year provided.
    //   - y should be a positive integer.
    // Postcondition: Initializes the dateType object with the provided values for month, day, and year.
    dateType(int m, int d, int y);

    // Setter function to set date
    // Precondition:
    //   - m should be a valid month (1-12).
    //   - d should be a valid day corresponding to the month and year provided.
    //   - y should be a positive integer.
    // Postcondition: Sets the date of the dateType object to the provided values.
    void setDate(int m, int d, int y);
    // Function to print the date
    // Precondition: None
    // Postcondition: Prints the date in the format "mm/dd/yyyy".
    void print() const;

    int getDay() const;   // Getter function for day
    int getMonth() const; // Getter function for month
    int getYear() const;  // Getter function for year

private:
    int dDay;
    int dMonth;
    int dYear;
    // Function to check if a year is a leap year
    // Precondition: None
    // Postcondition: Returns true if the provided year is a leap year, false otherwise.
    bool isLeapYear(int year) const;
    // Function to get the number of days in a month
    // Precondition: None
    // Postcondition: Returns the number of days in the provided month and year.
    int daysInMonth(int month, int year) const;
};

