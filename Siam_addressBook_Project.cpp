#include "addressBookType.h"

int main() {
    // Example usage
    addressBookType addressBook;
    addressBook.initEntry("AddressBookData.txt");
    extPersonType siam("siam", "sadid", 8, 21, 1998, "821 Forrest Dr.", "Newport News", "VA", "23606", "757-896-2960", "Friend");
    addressBook.addEntry(siam);
    addressBook.print();
    //addressBook.findBirthdays(12);
    addressBook.findRelations("Business");
    addressBook.sortEntries();
    addressBook.print();

    return 0;
}
