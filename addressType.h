#pragma once
#include <iostream>
using namespace std;

class addressType
{
private:
	string address = "";
	string city = "";
	string state = "XX";
	int zipcode = 10000;
public: 
	void print();
	//preconditions: address, city, state and zipcode must be supplied.
	// postconditions: uses supplied values.
	addressType(string = ("(Your address)"), string = ("(Your city)"), string = ("(XX)"), int = 10000);
	//preconditions: an address vlue is needed.
	//Postconditions: Uses given value for address else remains blank.
	void setAddress(string add) { address = add; }
	//preconditions: needs city name.
	//postxconditions: uses given name else it remains empty.
	void setCity(string cit) { city = cit; }
	//setState
	//preconditions: The given info is in valid format "XX"
	// postconditions: Uses given info else uses default value.
	void setState(string st);
	//preconditions: Needs 5 digit zipcode to work
	//postxconditions: uses given zipcode else it uses default value (10000)
	void setZipcode(int zip);

	string getAddress() { return address; }
	string getCity() { return city; }
	string getState() { return state; }
	int getZipcode() { return zipcode; }
	

	
};

