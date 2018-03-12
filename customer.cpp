// Implementation of customer.h


#include "customer.h"
#include <iostream>

Customer::Customer(string nId, string nLastName, string nFirstName) {
	setId(nId);
	setFirst(nFirstName);
	setLast(nLastName);
}

Customer::~Customer() {

}

// Iterate through the history vector, and output to the screen
void Customer::iterateHistory() {
	for (std::vector<Item *>::iterator it = history.begin();
	     it != history.end(); ++it) {
		cout << ' ' << *it << endl;
	}
}

// Return movie from the map
bool Customer::borrowItem(Item *item) {
	for (auto const &it: currentItems){
		if (it == item) { // Item exists in the currentItems, Increase the stock by one
			it->setStock(it->getStock() + 1);
			return true;
		}
	}
	item->setStock(1); // New
	currentItems.push_back(item);
	history.push_back(item);
	return true;
}

bool Customer::returnItem(Item *item) {
	/*auto it = std::find(currentItems.begin(), currentItems.end(), item);
	if(it != currentItems.end()){
		currentItems.erase(it);
		return true;
	}else{
		return false;
	}*/

	for (auto const &it: currentItems) {
		if (it == item) { // Item exists in the currentItems
			if (it->getStock() > 0) { // The customer currently checked out the movie
				it->setStock(it->getStock() - 1);
				return true;
			}
		}
	}

	return false; // Can't find movie or the customer has already returned the movie
}

bool Customer::setFirst(string first) {
	if (first == "") {
		cout << "Cannot set first" << endl;
		return false;
	}
	firstName = first;
	return true;
}

bool Customer::setLast(string last) {
	if (last == "") {
		cout << "Cannot set last" << endl;
		return false;
	}
	lastName = last;
	return true;
}

bool Customer::setId(string nId) {
	if (nId.size() != 4) {
		cout << "Cannot set first" << endl;
		return false;
	}
	id = nId;
	return true;
}

string Customer::getFirstName() const {
	return firstName;
}

string Customer::getLastName() const {
	return lastName;
}

string Customer::getID() const {
	return id;
}
