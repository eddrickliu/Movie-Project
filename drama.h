//
//  drama.h
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//
#include <string>
#include "movie.h"

#ifndef Drama_h
#define Drama_h

using namespace std;

class Drama : public Movie {
public:
	explicit Drama(string director, int stock, string title, int year);

	~Drama();

	friend ostream &operator<<(ostream &os, const Item &i);

	friend istream &operator>>(istream &is, Item &i);

	bool operator==(const Item &i) const;
};

#endif /* Drama_h */
