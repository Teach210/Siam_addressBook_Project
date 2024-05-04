#include "personType.h"
#include <iostream>
#include <cctype>

// Constructor
personType::personType(std::string a_firstName, std::string a_lastName) {
    a_firstName[0] = std::toupper(a_firstName[0]);
    a_lastName[0] = std::toupper(a_lastName[0]);
    firstName = a_firstName;
    lastName = a_lastName;
}

// Setters
void personType::setFirstName(std::string a_firstName) {
    a_firstName[0] = std::toupper(a_firstName[0]);
    firstName = a_firstName;
}

void personType::setLastName(std::string a_lastName) {
    a_lastName[0] = std::toupper(a_lastName[0]);
    lastName = a_lastName;
}

// Getters
std::string personType::getFirstName() const {
    return firstName;
}

std::string personType::getLastName() const {
    return lastName;
}

// Print function
void personType::print() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
}