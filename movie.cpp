/**
 * Implementation of movie.h
 */

#include "movie.h"
#include <iostream>

Movie::Movie(int year, string director, string title, int stock) : Item(stock,
                                                                        title) {
	setYear(year);
	setDirector(director);
}

bool Movie::setYear(int newYear) {
	if (newYear < 1888 || newYear > 2018) {
		cout << "newYear parameter must be between 1888 and 2018" << endl;
		return false;
	}
	this->year = newYear;
	return true;
}

bool Movie::setDirector(string newDirector) {
	if (newDirector.empty()) {
		cout << "newDirector parameter cannot be left empty" << endl;
		return false;
	}
	this->director = newDirector;
	return true;
}

int Movie::getYear() const {
	return year;
}

string Movie::getDirector() const {
	return director;
}

ostream &operator<<(ostream &os, const Movie &m) {
	os << m.getYear() << m.getDirector() << m.getTitle() << m.getStock();
	return os;
}

istream &operator>>(istream &is, const Movie &m) {
//	is >> m.getYear() >> m.getDirector() >> m.getTitle() >> m.getStock();
	return is;
}

bool Movie::operator==(const Movie &m) const{
	if (Item::operator==(m) == false) {
		return false;
	}
	return ( this->director == m.director) &&  ( this->year == m.year);
}