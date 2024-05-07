#include "addressBookType.h"
#include <iostream>
#include "extPersonType.h" // Include the header for extPersonType
#include <fstream>

// Constructor
addressBookType::addressBookType() {
    // No need to initialize length, as it's no longer used
}

// Member function implementations
void addressBookType::initEntry(std::string filename) {
    std::ifstream inFile(filename); // Open file for reading
    std::string firstName, lastName, addy, city, state, zip, phone, relation;
    int month, day, year;
    extPersonType person;

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

        // Use addEntry instead of direct assignment
        addEntry(person);
    }
    inFile.close(); // Close the file after reading
}

void addressBookType::addEntry(extPersonType person) {
    insert(person); // Use insert function of orderedLinkedList
}

void addressBookType::findPerson(std::string lastName) {
    // Use a traversal of nodes instead of array iteration
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        if (current->info.getLastName() == lastName) {
            current->info.print();
            return;
        }
        current = current->link;
    }
    std::cout << "Person with last name " << lastName << " not found." << std::endl;
}

void addressBookType::findBirthdays(int month) {
    // Use a traversal of nodes instead of array iteration
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        if (current->info.getBirthMonth() == month) {
            std::cout << current->info.getFirstName() << " " << current->info.getLastName() << std::endl;
        }
        current = current->link;
    }
}

void addressBookType::findRelations(std::string relationship) {
    // Use a traversal of nodes instead of array iteration
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        if (current->info.getRelationship() == relationship) {
            std::cout << current->info.getFirstName() << " " << current->info.getLastName() << std::endl;
        }
        current = current->link;
    }
}

void addressBookType::print() {
    // Use a traversal of nodes instead of array iteration
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        current->info.print();
        current = current->link;
    }
}