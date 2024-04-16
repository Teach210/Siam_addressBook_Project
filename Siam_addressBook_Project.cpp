#include <iostream>
#include "addressType.h"
using namespace std;

int main()
{
    cout << "Testing default constructor ..." << endl;
    addressType defAddress;
    defAddress.print();
    cout << endl;

    cout << "Testing constructors with parameters ..." << endl;
    addressType address("123 South Street", "Newport News", "VA", 23664);
    address.print();
    cout << endl;

    cout << "Testing invalid state (Virginia) ..." << endl;
    address.setState("Virginia");
    address.print();
    cout << endl;

    cout << "Testing invalid zipcode ..." << endl;
    address.setZipcode(555555555);
    address.print();
    cout << endl;

    cout << "Testing valid address ..." << endl;
    address.setAddress("44 East Main Street");
    address.setCity("Hapmton");
    address.setState("VA");
    address.setZipcode(23669);
    address.print();
    cout << endl;


    return 0;
}

