// Implementation of comedy.h

#include "comedy.h"

using namespace std;

Comedy::Comedy(string director, int stock, string title, int year) :
		Movie(year, director, title, stock) {

}

~Comedy::Comedy() {

}

ostream &operator<<(ostream &os, const Item &i){

}

istream &operator>>(istream &is, Item &i) {

}

bool operator==(const Comedy &i) const {

}