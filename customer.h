/**
 * Class that represents an individual customer. Keeps track of viewing history,
 * as well as current movies check out by the customer
 */

#ifndef ASSIGNMENT4_CUSTOMER_H
#define ASSIGNMENT4_CUSTOMER_H

#include <vector>
#import "movie.h"
#import "item.h"

using namespace std;

class Customer {
private:
	// Current movies checked out by the customer
	vector<Item *> currentItems;
	string id; // 4 digits
	string lastName; // Null check
	string firstName; // Null check
	vector<Item *> history;

public:
	explicit Customer(int id, string firstName, string lastName);

	~Customer();

	// Iterate through the history vector, and output to the screen
	void iterateHistory();

	// Add movie to the map
	// Also Add movie the history
	bool borrowItem(Item *item) const;

	bool returnItem(Item *item) const;

	bool setfirst(string first);
	bool setLast(string last);
	bool setId(int ID);
	string getFirst() const;
	string getLast() const;
	int getID() const;

};

#endif
