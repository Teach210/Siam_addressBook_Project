#include "extPersonType.h"
#include <stdexcept>

// Constructor
extPersonType::extPersonType(std::string first, std::string last, int birthMonth, int birthDay, int birthYear,
    std::string addr, std::string city, std::string state, int zipcode,
    std::string phone, std::string relation)
    : personType(first, last), address(addr, city, state, zipcode),
    birthDate(birthMonth, birthDay, birthYear), phoneNumber(phone) {
    // Set relationship with validation
    setRelationship(relation);
}

// Setter and getter for phone number
void extPersonType::setPhoneNumber(std::string phone) {
    phoneNumber = phone;
}

std::string extPersonType::getPhoneNumber() const {
    return phoneNumber;
}

// Setter and getter for relationship
void extPersonType::setRelationship(std::string relation) {
    if (relation != "Family" && relation != "Friend" && relation != "Business") {
        std::cerr << "Warning: Invalid relationship type. Allowed values are Family, Friend, or Business. Setting relationship to Unknown." << std::endl;
        relationship = " ";
    }
    else {
        relationship = relation;
    }
}

std::string extPersonType::getRelationship() const {
    return relationship;
}

// Getter for birth month
int extPersonType::getBirthMonth() const {
    return birthDate.getMonth();
}

// Method to print person information
void extPersonType::print() const {
    personType::print(); // Call the base class print method
    std::cout << "Birth Date: " << birthDate.getMonth() << "-" << birthDate.getDay() << "-" << birthDate.getYear() << std::endl;
    std::cout << "Address: " << address.getAddress() << std::endl;
    std::cout << "City: " << address.getCity() << std::endl;
    std::cout << "State: " << address.getState() << std::endl;
    std::cout << "Zipcode: " << address.getZipcode() << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Relationship: " << getRelationship() << std::endl;
}