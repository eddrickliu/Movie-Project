// Implementation of classic.h

#include "classic.h"

Classic::Classic(int stock, std::string director, std::string title,
                 std::string actor, int month, int year) :
		Movie(year, director, title, stock) {
	setActor(actor);
	setMonth(month);
}

~Classic() {

}

bool setActor(std::string actor) {
	if (actor == "") {
		cout << "Cant Set Actor" << std::endl;
		return false;
	}
	this->actor = actor;
	return true;
}

string getActor() {
	return actor;
}

bool setMonth(int month) {
	if (month > 12 || month < 1) {
		cout << "Cant Set Month" << endl;
		return false;
	}

	return true;
}

int getMonth() {
	return month;
}

ostream &operator<<(ostream &os, const Classic &i) {
	os << i.getYear() << i.getDirector() << i.getTitle() << i.getStock();
}

istream &operator>>(istream &is, Item &i) {
	is >> i.year >> i.director >> i.title >> i.stock;
	return is;
}

bool operator==(const Item &i) const {

	return Movie::operator==(i);
}
