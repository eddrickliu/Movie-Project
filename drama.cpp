// Implementation of drama.h

#include "drama.h"

Drama::Drama(string director, int stock, string title, int year) :
		Movie(year, director, title, stock) {

}

~Drama::Drama() {

}

ostream &operator<<(ostream &os, const Item &i) {

}

istream &operator>>(istream &is, Item &i) {

}

bool Drama::operator==(const Drama &i) const {
	return (
			i.getStock() == this->getStock()
			&& i.getTitle() == this->getTitle()
			&& i.getDirector() == this->getDirector()
			&& i.getYear() == this->getYear()
	)
}