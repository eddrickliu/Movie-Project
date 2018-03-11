// Implementation of customer.h

#include "customer.h"
#include <iostream>
using namespace std;

Customer::Customer(int nId, string nLastName, string nFirstName) {
    id = nId;
    lastName = nLastName;
    firstName = nFirstName;
}

Customer::~Customer() {

}

// Iterate through the history vector, and output to the screen
void Customer::iterateHistory() {
    std::vector<Item *>::iterator it = currentItems.begin();
    while(it != currentItems.end()){
        cout<<*it;
        ++it;
    }
}

// Return movie from the map
bool Customer::borrowItem(Item *item) const {
    currentItems.push_back(item);
}

bool Customer::returnItem(Item *item) const {
    currentItems.erase(item);
}

bool Customer::setfirst(string first){
    if (first == ""){
        cout << "Cannot set first" << endl;
        return false;
    }
    firstName = first;
    return true;
}
bool Customer::setLast(string last){
    if (last == ""){
        cout << "Cannot set last" << endl;
        return false;
    }
    lastName = last;
    return true
}
bool Customer::setId(string ID){
    if (ID.size() == 4){
        cout << "Cannot set first" << endl;
        return false;
    }
    firstName = first;
}
string Customer::getFirst() const{
    return firstName;
}
string Customer::getLast() const{
    return lastName;
}
int Customer::getID() const{
    return id;
}