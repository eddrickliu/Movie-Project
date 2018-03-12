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
	explicit Drama(int stock, string director, string title, int year);

	bool operator>(const Drama &d) const;

	bool operator<(const Drama &d) const;
};

#endif /* Drama_h */
