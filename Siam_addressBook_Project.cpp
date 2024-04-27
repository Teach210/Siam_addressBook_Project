#include <iostream>
#include "personType.h"

int main() {
    // Creating an instance of personType
    personType person("John", "Doe");

    // Printing person's information
    person.print();

    // Updating person's first name
    person.setFirstName("Jane");

    // Printing updated information
    person.print();

    return 0;
}