//
//  Classic.h
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//
#include <string>
#include "movie.h"
using namespace std;

#ifndef Classic_h
#define Classic_h

class Classic : public Movie {
private:
    int month;
    string actor;
public:
    explicit Classic(int stock ,std::string director,std::string title,std::string actor,int month, int year);
    ~Classic();
    bool setActor(std::string);
    string getActor();
    bool setMonth(int);
    int getMonth();
    friend std::ostream& operator<<(std::ostream& os, const Item& i);
    friend std::istream& operator>>(std::istream& is, Item& i);
    bool operator==(const Item &i) const;
};


#endif /* Classic_h */
