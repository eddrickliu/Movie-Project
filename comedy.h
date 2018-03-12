/**
 * This Comedy class...
 */

#include <string>
#include "movie.h"

#ifndef Comedy_h
#define Comedy_h

using namespace std;

class Comedy : public Movie {
public:
	explicit Comedy(int stock, string director, string title, int year);

	bool operator>(const Comedy &c) const;

	bool operator<(const Comedy &c) const;
};

#endif /* Comedy_h */
