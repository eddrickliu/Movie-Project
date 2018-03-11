/**
 *  This movie class...
 */

#include "item.h"
#include <string>

#ifndef movie_h
#define movie_h

using namespace std;

class Movie : public Item {
private:
	string director;
	int year;

public:
	explicit Movie(int stock, string director, string title,
	               int year);

	bool setDirector(string);

	bool setYear(int year);

	int getYear() const;

	string getDirector() const;

	friend ostream &operator<<(ostream &os, const Movie &m);

	friend istream &operator>>(istream &is, const Movie &m);

	bool operator==(const Movie &i) const;
};

#endif
