#pragma once
#include "personType.h" // Include the base class header
#include "dateType.h"   // Include the header for dateType
#include "addressType.h" // Include the header for addressType

class extPersonType : public personType {
private:
    addressType address;   // Instance of addressType for address
    dateType birthDate;    // Instance of dateType for birth date
    std::string phoneNumber;
    std::string relationship;

public:

    // Default constructor
    // Precondition: None
    // Postcondition: Sets the person's first and last name to empty strings, 
    // sets the address to default values (" ", " ", "XX", "10000"), 
    // sets the birth date to default values, sets phone number and relationship to empty strings.
    extPersonType() : personType("", ""), address(" ", " ", "XX", "10000"), birthDate(), phoneNumber(""), relationship("") {}

    // Constructor
    // Precondition: None
    // Postcondition: Sets the person's first and last name to the provided arguments, 
    // sets the birth date to the provided arguments, sets the address to the provided arguments,
    // sets phone number and relationship to the provided arguments.
    extPersonType(std::string first, std::string last, int birthMonth, int birthDay, int birthYear,
        std::string addr, std::string city, std::string state, std::string zipcode,
        std::string phone, std::string relationship);

    // Setter and getter for phone number
    // Precondition: None
    // Postcondition: Sets the phone number to the provided argument.
    void setPhoneNumber(std::string phone);
    // Precondition: None
    // Postcondition: Returns the phone number.
    std::string getPhoneNumber() const;

    // Setter and getter for relationship
    // Precondition: None
    // Postcondition: Sets the relationship to the provided argument.
    void setRelationship(std::string relation); // Corrected parameter name here
    // Precondition: None
    // Postcondition: Returns the relationship.
    std::string getRelationship() const;

    // Getter for birth month
    // Precondition: None
    // Postcondition: Returns the birth month.
    int getBirthMonth() const;

    // Precondition: None
    // Postcondition: Returns the birth day.
    int getBirthDay() const;

    // Precondition: None
    // Postcondition: Returns the birth year.
    int getBirthYear() const;

    // Precondition: None
    // Postcondition: Returns the address.
    std::string getAddy() const;

    // Precondition: None
    // Postcondition: Returns the city.
    std::string getCity() const;

    // Precondition: None
    // Postcondition: Returns the state.
    std::string getState() const;

    // Precondition: None
    // Postcondition: Returns the ZIP code.
    std::string getZipCode() const;

    // Setters

    // Precondition: None
    // Postcondition: Sets the birth date to the provided arguments.
    void setBirthDate(int m, int d, int y);

    // Precondition: None
    // Postcondition: Sets the address to the provided argument.
    void setAddy(std::string add);

    // Precondition: None
    // Postcondition: Sets the city to the provided argument.
    void setCity(std::string city);

    // Precondition: None
    // Postcondition: Sets the state to the provided argument.
    void setState(std::string state);

    // Precondition: None
    // Postcondition: Sets the ZIP code to the provided argument.
    void setZipCode(std::string zip);


    // Method to print person information
    // Precondition: None
    // Postcondition: Prints person's information.
    void print() const;

    // Overloaded operators

    // Precondition: None
    // Postcondition: Returns true if this person's last name is greater than or equal to the other person's last name; otherwise, returns false.
    bool operator>=(const extPersonType& other) const;

    // Precondition: None
    // Postcondition: Returns true if this person's last name is equal to the other person's last name; otherwise, returns false.
    bool operator==(const extPersonType& other) const;

    // Precondition: None
    // Postcondition: Returns true if this person's last name is less than or equal to the other person's last name; otherwise, returns false.
    bool operator<=(const extPersonType& other) const;

    // Precondition: None
    // Postcondition: Returns true if this person's last name is not equal to the other person's last name; otherwise, returns false.
    bool operator!=(const extPersonType& other) const;
};

