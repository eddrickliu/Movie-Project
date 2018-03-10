// Implementation of customer.h

#include "customer.h"

explicit Customer(int id, string lastName, string FirstName) {

}

~Customer() {

}

// Iterate through the history vector, and output to the screen
void Customer::iterateHistory() {

}

// Return movie from the map
bool Customer::borrowItem(Item &item) const {
	currentItems.push_back(item);
}

bool Customer::returnItem(Item &item) const {
	currentItems.erase(currentItems.begin() + , customerItems.begin() + 3);
}