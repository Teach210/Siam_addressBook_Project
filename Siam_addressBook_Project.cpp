#include <iostream>
#include "addressBookType.h" // Include the header for addressBookType
using namespace std;

int showMenu() {
    int choice;

    cout << "Main Menu" << endl; // Replace with an appropriate heading
    cout << "Select an option:" << endl;
    cout << "1 - Add Entry" << endl;
    cout << "2 - Find Person" << endl;
    cout << "3 - Find Birthdays" << endl;
    cout << "4 - Find Relations" << endl;
    cout << "5 - Print Address Book" << endl;
    cout << "6 - Quit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main() {
    addressBookType addressBook;
    addressBook.initEntry("AddressBookData.txt"); // Assuming "AddressBookData.txt" is the file containing initial data

    int choice;

    do {
        choice = showMenu();

        switch (choice) {
        case 1:
            // Add Entry
        {
            extPersonType newPerson;
            string firstName, lastName, addy, city, state, zip, phone, relation;
            int month, day, year;

            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter birth date (MM DD YYYY): ";
            cin >> month >> day >> year;
            cout << "Enter address: ";
            cin.ignore(); // Clear the newline character from the buffer
            getline(cin, addy);
            cout << "Enter city: ";
            getline(cin, city);
            cout << "Enter state: ";
            cin >> state;
            cout << "Enter zip code: ";
            cin >> zip;
            cout << "Enter phone number: ";
            cin >> phone;
            cout << "Enter relationship: ";
            cin >> relation;

            newPerson.setFirstName(firstName);
            newPerson.setLastName(lastName);
            newPerson.setBirthDate(month, day, year);
            newPerson.setAddy(addy);
            newPerson.setCity(city);
            newPerson.setState(state);
            newPerson.setZipCode(zip);
            newPerson.setPhoneNumber(phone);
            newPerson.setRelationship(relation);

            addressBook.addEntry(newPerson);
            cout << "New entry added successfully." << endl;
        }
        break;
        case 2:
            // Find Person
        {
            string lastName;
            cout << "Enter last name to find: ";
            cin >> lastName;
            addressBook.findPerson(lastName);
        }
        break;
        case 3:
            // Find Birthdays
        {
            int month;
            cout << "Enter birth month to find: ";
            cin >> month;
            addressBook.findBirthdays(month);
        }
        break;
        case 4:
            // Find Relations
        {
            string relationship;
            cout << "Enter relationship to find: ";
            cin >> relationship;
            addressBook.findRelations(relationship);
        }
        break;
        case 5:
            // Print Address Book
            addressBook.print();
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}