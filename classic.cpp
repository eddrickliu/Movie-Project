/**
 * Implementation of classic.h
 */

#include "classic.h"
#include <iostream>

Classic::Classic(int stock, std::string director, std::string title,
                 std::string actor, int month, int year) :
		Movie(stock, director, title, year) {
	setActor(actor);
	//cout << month
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
	this->month = month;
	return true;
}

int Classic::getMonth() const {
	return month;
}

ostream &operator<<(ostream &os, const Classic &c) {
	os << c.getYear() << " " << c.getMonth() << " " << c.getDirector()
	   << " " << c.getActor() << " " << c.getTitle() << " " << c.getStock();
	return os;
}


bool Classic::operator==(const Classic &c) const {
	if (Movie::operator==(c) == false) {
		return false;
	}
	return (this->month == c.month) && (this->actor == c.actor);
}

bool Classic::operator>(const Classic &c) const {
	if (this->getYear() < c.getYear()) {
		return false;
	} else if (this->getMonth() < c.getMonth()) {
		return false;
	} else if (this->getActor() < c.getActor()) {
		return false;
	}
	return true;
}

bool Classic::operator<(const Classic &c) const {
	if (this->getYear() > c.getYear()) {
		return false;
	} else if (this->getMonth() > c.getMonth()) {
		return false;
	} else if (this->getActor() > c.getActor()) {
		return false;
	}
	return true;
}
