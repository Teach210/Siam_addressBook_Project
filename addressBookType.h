#pragma once
#include <string>
#include "extPersonType.h"
#include "orderedLinkedList.h"


class addressBookType : public orderedLinkedList<extPersonType> {

public:
    addressBookType();

    // Member function declarations

    // Initializes the address book with entries from a file
    void initEntry(std::string data);
    // Precondition: data is a valid path to an existing file containing person information in the specified format.
    // Postcondition: Reads person information from the file and adds it to the address book.

    // Adds a new entry to the address book
    void addEntry(extPersonType person);
    // Precondition: person is a valid extPersonType object.
    // Postcondition: Adds the person to the address book.

    // Finds a person by their first and last name
    nodeType<extPersonType>* findPerson(std::string firstName, std::string lastName);
    // Precondition: firstName and lastName are valid strings representing a person's first and last names.
    // Postcondition: Returns a pointer to the node containing the person with the given first and last names, if found; otherwise, returns nullptr.

    // Finds people with birthdays in a given month
    void findBirthdays(int month);
    // Precondition: month is a valid integer representing a month (1-12).
    // Postcondition: Prints the names of people with birthdays in the given month.

    // Finds people with a given relationship status
    void findRelations(std::string relationship);
    // Precondition: relationship is a valid string representing a relationship status.
    // Postcondition: Prints the names of people with the given relationship status.

    // Prints the entire address book
    void print();
    // Precondition: None
    // Postcondition: Prints all entries in the address book.

    // Adds a new entry interactively
    void addEntryInteractive();
    // Precondition: None
    // Postcondition: Prompts the user to enter information for a new person and adds it to the address book.

    // Removes an entry from the address book
    void removeEntry(std::string firstName, std::string lastName);
    // Precondition: firstName and lastName are valid strings representing a person's first and last names.
    // Postcondition: Removes the entry of the person with the given first and last names from the address book.

    // Saves the address book to a file
    void saveToFile(const std::string& filename) const;
    // Precondition: filename is a valid string representing the path to the file where the address book will be saved.
    // Postcondition: Writes the contents of the address book to the specified file.
};

