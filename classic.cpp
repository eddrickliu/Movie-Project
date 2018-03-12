/**
 * Implementation of classic.h
 */

#include "classic.h"
#include <iostream>

Classic::Classic(int stock, std::string director, std::string title,
                 std::string actor, int month, int year) :
		Movie(year, director, title, stock) {
	setActor(actor);
	setMonth(month);
}

bool Classic::setActor(std::string actor) {
	if (actor == "") {
		cout << "Cant Set Actor" << std::endl;
		return false;
	}
	this->actor = actor;
	return true;
}

string Classic::getActor() const {
	return actor;
}

bool Classic::setMonth(int month) {
	if (month > 12 || month < 1) {
		cout << "Cant Set Month" << endl;
		return false;
	}

	return true;
}

int Classic::getMonth() const {
	return month;
}

ostream &operator<<(ostream &os, const Classic &c) {
	os << c.getYear() << c.getMonth() << c.getDirector() << c.getActor()
	   << c.getTitle() << c.getStock();
	return os;
}

istream &operator>>(istream &is, const Classic &c) {
//	is >> i.getYear() >> i.getDirector() >> i.getTitle() >> i.getStock();
	return is;
}

bool Classic::operator==(const Classic &c) const {
	if (Movie::operator==(c) == false) {
		return false;
	}
	return ( this->month == c.month) &&  ( this->actor == c.actor);
}
