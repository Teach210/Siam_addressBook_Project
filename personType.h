#pragma once
#include <string>

class personType {
private:
    std::string firstName;
    std::string lastName;

public:
    personType(std::string a_firstName, std::string a_lastName);

    void setFirstName(std::string a_firstName);
    std::string getFirstName() const;

    void setLastName(std::string a_lastName);
    std::string getLastName() const;

    void print() const;
};

