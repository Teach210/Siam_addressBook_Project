#pragma once
#include <string>
#include "extPersonType.h"


class addressBookType {
private:
    extPersonType addressList[500];
    int length;
    const int MAX_LENGTH = 500;

public:
    addressBookType();

    void initEntry(std::string data);

    void addEntry(extPersonType person);

    void findPerson(std::string lastName);

    void findBirthdays(int month);

    void findRelations(std::string relationship);

    void print();

    void sortEntries();
};

