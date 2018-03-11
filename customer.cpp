// Implementation of customer.h


#include "customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string nId, string nLastName, string nFirstName) {
    id = nId;
    lastName = nLastName;
    firstName = nFirstName;
}

Customer::~Customer() {
    
}

// Iterate through the history vector, and output to the screen
void Customer::iterateHistory() {
    for (std::vector<Item *>::iterator it = history.begin(); it != history.end(); ++it){
        cout << ' ' << *it<<endl;
    }
}

// Return movie from the map
bool Customer::borrowItem(Item *item){
    currentItems.push_back(item);
    history.push_back(item);
    return true;
}

bool Customer::returnItem(Item *item){
    auto it = std::find(currentItems.begin(), currentItems.end(), item);
    if(it != currentItems.end()){
        currentItems.erase(it);
        return true;
    }else{
        return false;
    }
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
    return true;
}
bool Customer::setId(string nId){
    if (nId.size() != 4){
        cout << "Cannot set first" << endl;
        return false;
    }
    id = nId;
    return true;
}

string Customer::getFirstName() const{
    return firstName;
}
string Customer::getLastName() const{
    return lastName;
}

string Customer::getID() const{
    return id;
}
