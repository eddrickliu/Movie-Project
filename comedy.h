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


class comedy : public Movie{
public:
    explicit comedy(int stock ,std::string director,std::string title ,int year);
    ~comedy();
    friend std::ostream& operator<<(std::ostream& os, const Item& i);
    friend std::istream& operator>>(std::istream& is, Item& i);
    bool operator==(const Item &i) const;
}


#endif /* Comedy_h */
