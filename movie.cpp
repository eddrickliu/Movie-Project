//
//  Movie.cpp
//  Ass4
//
//  Created by Eddrick Liu on 3/9/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

#include "movie.h"
#include <iostream>
#include <stdio.h>
#include <string>

Movie::Movie(int year, std::string director, std::string title, int stock) :
		Item(stock, title) {
	setYear(year);
	setDirector(director);
}

Movie::~Movie() {

}

bool Movie::setYear(int year) {
	if (year < 1888 || year > 2018) {
		std::cout << "Cant Set Year" << std::endl;
		return false;
	}
	this->year = year;
	return true;
}

bool Movie::setDirector(std::string director) {
	if (director == "") {
		std::cout << "Cant Set Director" << std::endl;
		return false;
	}
	this->director = director;
	return true;
}

int Movie::getYear() const{
	return year;
}

std::string Movie::getDirector() const{
	return director;
}

bool Movie::operator==(const Item &i) const {
	if (typeid(i) == typeid(Movie)) {
		Movie *c = static_cast<Movie *>(i);

		if (this->stock != i.stock) {
			return false;
		} else if (this->title != i.title) {
			return false;
		} else if (this->director != i.director) {
			return false;
		} else if (this->year != i.year) {
			return false;
		}
		return true;
	}
	return false;
}

std::ostream &operator<<(std::ostream &os, const Item &i) {
	os << i.year << i.director << i.title << i.stock;
	return os
}

std::istream &operator>>(std::istream &is, Item &i) {
	is >> i.year >> i.director >> i.title >> i.stock;
	return is;
}
