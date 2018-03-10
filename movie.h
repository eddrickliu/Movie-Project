//
//  movie.h
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//
#include "item.h"
#include <string>

#ifndef movie_h
#define movie_h

class Movie : public Item {
private:
	std::string director; // Null check
	int year;
public:
	explicit Movie(int year, std::string director, std::string title,
	               int stock);

	virtual ~Movie();

	bool setDirector(std::string);

	bool setYear(int year);

	int getYear();

	std::string getDirector();

	friend std::ostream &operator<<(std::ostream &os, const Item &i);

	friend std::istream &operator>>(std::istream &is, Item &i);

	bool operator==(const Item &i) const;
};

#endif /* movie_h */
