/**
 * Class that represents an individual customer. Keeps track of viewing history,
 * as well as current movies check out by the customer
 */


#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <vector>
#include "movie.h"
#include "item.h"

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
    explicit Customer(string id, string firstName, string lastName);
    
    ~Customer();
    
    // Iterate through the history vector, and output to the screen
    void iterateHistory();
    
    // Add movie to the map
    // Also Add movie the history
    bool borrowItem(Item *item);
    
    bool returnItem(Item *item);
    
    bool setFirst(string first);
    bool setLast(string last);
    bool setId(string nId);
    string getFirstName() const;
    string getLastName() const;
    string getID() const;
    
};

#endif
