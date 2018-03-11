/**
 * Implementation of drama.h
 */

#include "drama.h"

Drama::Drama(int stock, string director, string title,int year) :
		Movie(year, director, title, stock) {
}
bool Drama::operator>(const Drama &d) const{
	if (this->getDirector() < d.getDirector()){
		return false;
	}
	else if (this->getTitle() < d.getTitle()){
		return false;
	}
	return true;
}

bool Drama::operator<(const Drama &d) const{
	if (this->getDirector() > d.getDirector()){
		return false;
	}
	else if (this->getTitle() > d.getTitle()){
		return false;
	}
	return true;
}
