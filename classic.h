/**
 * This Classic class
 */

#include <string>
#include "movie.h"

#ifndef Classic_h
#define Classic_h

using namespace std;

class Classic : public Movie {
private:
	int month;
	string actor;

public:
	explicit Classic(int stock, string director, string title,
	                 string actor, int month, int year);

	string getActor() const;

	int getMonth() const;

	bool setMonth(int);

	bool setActor(string);

	friend ostream &operator<<(ostream &os, const Classic &c);

	friend istream &operator>>(istream &is, const Classic &c);

	bool operator==(const Classic &i) const;

	bool operator>(const Classic &c) const;

	bool operator<(const Classic &c) const;
};

#endif /* Classic_h */
