#include "extPersonType.h"
#include <stdexcept>

// Constructor
extPersonType::extPersonType(std::string first, std::string last, int birthMonth, int birthDay, int birthYear,
    std::string addr, std::string city, std::string state, std::string zipcode,
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

void extPersonType::setBirthDate(int m, int d, int y) {
    birthDate.setDate(m, d, y);
}

// Getter for birth month
int extPersonType::getBirthMonth() const {
    return birthDate.getMonth();
}

// Getter for birth day
int extPersonType::getBirthDay() const {
    return birthDate.getDay();
}

// Getter for birth year
int extPersonType::getBirthYear() const {
    return birthDate.getYear();
}

void extPersonType::setAddy(std::string addy) {
    address.setAddress(addy);
}

std::string extPersonType::getAddy() const {
    return address.getAddress();
}

void extPersonType::setCity(std::string city) {
    address.setCity(city);
}

std::string extPersonType::getCity() const {
    return address.getCity();
}

void extPersonType::setState(std::string state) {
    address.setState(state);
}

std::string extPersonType::getState() const {
    return address.getState();
}

void extPersonType::setZipCode(std::string zip) {
    address.setZipcode(zip);
}

std::string extPersonType::getZipCode() const {
    return address.getZipcode();
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
    std::cout << "Relationship: " << getRelationship() << std::endl << std::endl;
}

// Overload the >= operator
bool extPersonType::operator>=(const extPersonType& other) const {
    // Implement the comparison logic based on your requirements
    // For example, compare based on last name and then first name
    if (this->getLastName() == other.getLastName()) {
        return this->getFirstName() >= other.getFirstName();
    }
    return this->getFirstName() >= other.getLastName();
}

// Overload the == operator
bool extPersonType::operator==(const extPersonType& other) const {
    // Implement the comparison logic based on your requirements
    return (this->getFirstName() == other.getFirstName() && this->getLastName() == other.getLastName());
}

// Overload the <= operator
bool extPersonType::operator<=(const extPersonType& other) const {
    // Implement the comparison logic based on your requirements
    if (this->getLastName() == other.getLastName()) {
        return this->getFirstName() <= other.getFirstName();
    }
    return this->getFirstName() <= other.getLastName();
}

bool extPersonType::operator!=(const extPersonType& other) const {
    // Implement the comparison logic based on your requirements
    return (this->getFirstName() != other.getFirstName() && this->getLastName() != other.getLastName());
}