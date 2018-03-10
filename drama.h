//
//  drama.h
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//
#include <string>
#include "movie.h"
<<<<<<< HEAD
using namespace std;
=======
>>>>>>> master

#ifndef Drama_h
#define Drama_h

<<<<<<< HEAD
class Drama : public Movie {
public:
    explicit Drama(int stock ,std::string director,std::string title ,int year);
    ~Drama();
    friend std::ostream& operator<<(std::ostream& os, const Item& i);
    friend std::istream& operator>>(std::istream& is, Item& i);
    bool operator==(const Item &i) const;
};
=======
using namespace std;

class Drama : public Movie {
public:
	explicit Drama(string director, int stock, string title, int year);

	~Drama();

	friend ostream &operator<<(ostream &os, const Item &i);

	friend istream &operator>>(istream &is, Item &i);
>>>>>>> master

	bool operator==(const Item &i) const;
};

#endif /* Drama_h */
