//
//  Drama.h
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//
#include <string>
#include “Movie.h”

#ifndef Drama_h
#define Drama_h

class Drama : public Movie {
public:
    explicit Drama(int stock ,std::string director,std::string title ,int year);
    ~Drama();
    riend std::ostream& operator<<(std::ostream& os, const Item& i);
    friend std::istream& operator>>(std::istream& is, Item& i);
    bool operator==(const Item &i) const;
}


#endif /* Drama_h */
