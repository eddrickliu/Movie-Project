//
//  comedy.h
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

#include <string>
#include "movie.h"

#ifndef Comedy_h
#define Comedy_h

using namespace std;

class Comedy : public Movie {
public:
	explicit Comedy(int stock, string director, string title, int year);

	~Comedy();

	friend ostream &operator<<(ostream &os, const Item &i);

	friend istream &operator>>(istream &is, Item &i);

	bool operator==(const Item &i) const;
}

#endif /* Comedy_h */
