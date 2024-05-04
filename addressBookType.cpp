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



        address[length] = person;

        recordCount++; 
        length++;
    }
    std::cout << recordCount << " records added from file" << std::endl;
    inFile.close(); // Close the file after reading
}

void addressBookType::addEntry(extPersonType person) {
    // Implement addEntry
    if (length < MAX_LENGTH) {
        address[length] = person;
        length++;
    }
    else {
        std::cerr << "Address list full! Can't add anymore entries." << std::endl;
    }
}

void addressBookType::findPerson(std::string lastName) {
    // Implement findPerson
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (address[i].getLastName() == lastName) {
            return address[i].print();
        }
    }
}

void addressBookType::findBirthdays(int month) {

}

void addressBookType::findRelations(std::string relationship) {
    // Implement findRelations
}

void addressBookType::print() {
    // Implement print
    for (int i = 0; i < length; i++) {
        std::cout << address[i].getFirstName() << " " << address[i].getLastName() << std::endl;
        std::cout << address[i].getBirthMonth() << "/" << address[i].getBirthDay() << "/" << address[i].getBirthYear() << std::endl;
        std::cout << address[i].getAddy() << std::endl;
        std::cout << address[i].getCity() << ", " << address[i].getState() << " " << address[i].getZipCode() << std::endl;
        std::cout << address[i].getPhoneNumber() << " " << address[i].getRelationship() << std::endl << std::endl;
    }
}

void addressBookType::sortEntries() {
    // Implement sortEntries
}