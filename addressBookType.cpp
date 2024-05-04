#include "addressBookType.h"
#include <iostream>
#include "extPersonType.h" // Include the header for extPersonType
#include <fstream>
// Constructor
addressBookType::addressBookType() {
    length = 0;
}

// Member function implementations
void addressBookType::initEntry(std::string filename) {
    std::ifstream inFile(filename); // Open file for reading
    std::string firstName, lastName, addy, city, state, zip, phone, relation;
    int month, day, year;
    extPersonType person;
    int recordCount = 0;
    
    if (!inFile.is_open()) {
        std::cerr << "Error: Failed to open file." << std::endl;
        return;
    }
    while (inFile >> firstName) {
        inFile >> lastName >> month >> day >> year;
        inFile.ignore();
        getline(inFile, addy);
        getline(inFile, city);
        inFile >> state >> zip >> phone >> relation;

        person.setFirstName(firstName);
        person.setLastName(lastName);
        person.setBirthDate(month, day, year);
        person.setAddy(addy);
        person.setCity(city);
        person.setState(state);
        person.setZipCode(zip);
        person.setPhoneNumber(phone);
        person.setRelationship(relation);



        addressList[length] = person;

        recordCount++; 
        length++;
    }
    std::cout << recordCount << " records added from file" << std::endl;
    inFile.close(); // Close the file after reading
}

void addressBookType::addEntry(extPersonType person) {
    // Implement addEntry
    if (length < MAX_LENGTH) {
        addressList[length] = person;
        length++;
    }
    else {
        std::cerr << "Address list full! Can't add anymore entries." << std::endl;
    }
}

void addressBookType::findPerson(std::string lastName) {
    // Implement findPerson
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (addressList[i].getLastName() == lastName) {
            return addressList[i].print();
        }
    }
}

void addressBookType::findBirthdays(int month) {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getBirthMonth() == month) {
            std::cout << addressList[i].getFirstName() << " " << addressList[i].getLastName() << std::endl;
        }
    }
}

void addressBookType::findRelations(std::string relationship) {
    // Implement findRelations
    for (int i = 0; i < length; i++) {
        if (addressList[i].getRelationship() == relationship) {
            std::cout << addressList[i].getFirstName() << " " << addressList[i].getLastName() << std::endl;
        }
    }
}

void addressBookType::print() {
    // Implement print
    for (int i = 0; i < length; i++) {
        std::cout << addressList[i].getFirstName() << " " << addressList[i].getLastName() << std::endl;
        std::cout << addressList[i].getBirthMonth() << "/" << addressList[i].getBirthDay() << "/" << addressList[i].getBirthYear() << std::endl;
        std::cout << addressList[i].getAddy() << std::endl;
        std::cout << addressList[i].getCity() << ", " << addressList[i].getState() << " " << addressList[i].getZipCode() << std::endl;
        std::cout << addressList[i].getPhoneNumber() << " " << addressList[i].getRelationship() << std::endl << std::endl;
    }
}

void addressBookType::sortEntries() {
    // Implement sortEntries
}