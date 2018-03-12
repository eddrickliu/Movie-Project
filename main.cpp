//
//  main.cpp
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

#include <iostream>
#include "item.h"
#include "movie.h"
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "customer.h"
#include "movie_store.h"

int main(int argc, const char * argv[]) {
    MovieStore* m1 = new MovieStore();
    m1->readMovies(data4movies.txt);
    m1->readCustomers(data4movies.txt);
    m1->readCommands(data4movies.txt);
}
