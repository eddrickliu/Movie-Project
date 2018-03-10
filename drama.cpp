// Implementation of drama.h

#include "drama.h"

Drama::Drama(int stock, std::string director, std::string title, int year) : Movie(year, director, title, stock){
}

Drama::~Drama() {

}

ostream &operator<<(ostream &os, const Item &i) {

}

istream &operator>>(istream &is, Item &i) {

}

bool Drama::operator==(const Item &i) const {
	if (typeid(i) == typeid(Drama)) {
		return Movie::operator==(i);
	}
	return false;
}
