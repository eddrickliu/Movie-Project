// Implementation of comedy.h

#include "comedy.h"

using namespace std;

Comedy::Comedy(int stock, std::string director, std::string title,
               int year) : Movie(year, director, title, stock){
    
}

Comedy::~Comedy() {

}

ostream &operator<<(ostream &os, const Item &i){
    
}

istream &operator>>(istream &is, Item &i) {

}

bool Comedy::operator==(const Item &i) const {

}
