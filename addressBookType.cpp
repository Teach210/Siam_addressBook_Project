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

nodeType<extPersonType>* addressBookType::findPerson(std::string firstName, std::string lastName) {
    // Use a traversal of nodes instead of array iteration
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        if (current->info.getFirstName() == firstName && current->info.getLastName() == lastName) {
            current->info.print();
            return current;
        }
        current = current->link;
    }
    std::cout << "Person with name " << firstName << " " << lastName << " not found." << std::endl;
    return nullptr;
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

void addressBookType::addEntryInteractive() {
    std::string firstName, lastName, addy, city, state, zip, phone, relation;
    int month, day, year;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter birthdate (MM DD YYYY): ";
    std::cin >> month >> day >> year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cout << "Enter address: ";
    std::getline(std::cin, addy);
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    std::cout << "Enter state: ";
    std::cin >> state;
    std::cout << "Enter zip code: ";
    std::cin >> zip;
    std::cout << "Enter phone number: ";
    std::cin >> phone;
    std::cout << "Enter relationship: ";
    std::cin >> relation;

    extPersonType newPerson(firstName, lastName, month, day, year, addy, city, state, zip, phone, relation);
    addEntry(newPerson);
}

void addressBookType::removeEntry(std::string firstName, std::string lastName) {
    // Use a traversal of nodes instead of array iteration
    nodeType<extPersonType>* nodeToDelete = findPerson(firstName, lastName);
    if (nodeToDelete != nullptr) {
        deleteNode(nodeToDelete->info);
        std::cout << firstName << " " << lastName << " successfully removed!" << std::endl;
    }
}

void addressBookType::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        outFile << current->info.getFirstName() << " "
            << current->info.getLastName() << "\n"
            << current->info.getBirthMonth() << " "
            << current->info.getBirthDay() << " "
            << current->info.getBirthYear() << "\n"
            << current->info.getAddy() << "\n"
            << current->info.getCity() << "\n"
            << current->info.getState() << "\n"
            << current->info.getZipCode() << "\n"
            << current->info.getPhoneNumber() << "\n"
            << current->info.getRelationship() << std::endl;
        current = current->link;
    }
   

    outFile.close();
}
