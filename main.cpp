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
void movieTests(){
    cout << "Movie Tests: " << endl;
    Movie m1(10,"Quentin Taratino","Hateful Eight",2015);
    Movie m2(10,"Quentin Taratino","Hateful Eight",2015);
    //    cout << m1.getYear() << endl;
    //    cout << m1.getDirector() << endl;
    //    cout << m1.getTitle() << endl;
    //    cout << m1.getStock() << endl;
    cout << m1 << endl;
    cout << (m1 == m2) << endl;

    cout << "Drama Tests: " << endl;
    Drama d1(2017,"Logan Paul","Planet of Apes",16);
    Drama d2(2017,"Jake Paul","Planet of Apes",16);
    cout << d1 << endl;
    cout << (d1==d2)<<endl;

    cout << "Comedy Tests: " << endl;
    Comedy f1(2016,"Adam Sandler","Daddy's Home",6);
    Comedy f2(2006,"Adam Sandler","Daddy's Home",6);
    cout << f1 << endl;
    cout << (f1==f2)<<endl;

    cout << "Classic Tests: " << endl;
    Classic c1(3,"Quentin Tartino","Pulp Fiction",
               "Samuel Jackson",4,1994);
    Classic c2(3,"Quentin Tartino","Pulp Fiction",
               "Samuel Jackson",4,1994);
    cout << c1 << endl;
    cout << (c1==c2)<<endl;
}

int main(int argc, const char * argv[]) {
    MovieStore* m1 = new MovieStore();
    m1->readMovies("data4movies.txt");
    m1->readCustomers("data4movies.txt");
    m1->readCommands("data4movies.txt");
    movieTests();
}

