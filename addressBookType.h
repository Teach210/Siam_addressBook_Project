#pragma once
#include <string>
#include "extPersonType.h"
#include "orderedLinkedList.h"


class addressBookType : public orderedLinkedList<extPersonType>{

public:
    addressBookType();

    void initEntry(std::string data);

    void addEntry(extPersonType person);

    nodeType<extPersonType>* findPerson(std::string firstName, std::string lastName);

    void findBirthdays(int month);

    void findRelations(std::string relationship);

    void print();

    // Function to add a new entry interactively
    void addEntryInteractive();

    // Function to remove an entry
    void removeEntry(std::string firstName, std::string lastName);

};

