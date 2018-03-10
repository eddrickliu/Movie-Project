// Implementation of drama.h

#include "drama.h"

<<<<<<< HEAD
Drama::Drama(int stock, std::string director, std::string title, int year) : Movie(year, director, title, stock){
    
=======
Drama::Drama(string director, int stock, string title, int year) :
		Movie(year, director, title, stock) {

>>>>>>> master
}

Drama::~Drama() {

}

ostream &operator<<(ostream &os, const Item &i) {

}

istream &operator>>(istream &is, Item &i) {

}

bool Drama::operator==(const Item &i) const {
<<<<<<< HEAD

}
=======
	if (typeid(i) == typeid(Drama)) {
		return Movie::operator==(i);
	}
	return false;
}
>>>>>>> master
