//
//  comedy.h
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

<<<<<<< HEAD
#include "movie.h"
using namespace std;
=======
#include <string>
#include "movie.h"
>>>>>>> master

#ifndef Comedy_h
#define Comedy_h

using namespace std;

<<<<<<< HEAD
class Comedy : public Movie{
public:
    explicit Comedy(int stock ,std::string director,std::string title ,int year);
    ~Comedy();
    friend std::ostream& operator<<(std::ostream& os, const Item& i);
    friend std::istream& operator>>(std::istream& is, Item& i);
    bool operator==(const Item &i) const;
};
=======
class Comedy : public Movie {
public:
	explicit Comedy(int stock, string director, string title, int year);

	~Comedy();

	friend ostream &operator<<(ostream &os, const Item &i);
>>>>>>> master

	friend istream &operator>>(istream &is, Item &i);

	bool operator==(const Item &i) const;
}

#endif /* Comedy_h */
