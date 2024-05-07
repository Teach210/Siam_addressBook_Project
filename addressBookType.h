#pragma once
#include <string>
#include "extPersonType.h"
#include "orderedLinkedList.h"


class addressBookType : public orderedLinkedList<extPersonType>{

public:
    addressBookType();

    void initEntry(std::string data);

    void addEntry(extPersonType person);

    void findPerson(std::string lastName);

    void findBirthdays(int month);

    void findRelations(std::string relationship);

    void print();

};

