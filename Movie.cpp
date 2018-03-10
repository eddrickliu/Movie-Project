//
//  Movie.cpp
//  Ass4
//
//  Created by Eddrick Liu on 3/9/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

#include "Movie.h"
#include <iostream>
#include <stdio.h>
#include <string>

Movie::Movie(int year, std::string director, std::string title, int stock):
Item(stock,title){
    setYear(year);
    setDirector(director);
}

bool Movie::setYear(int year){
    if ( year < 1888 || year > 2018){
        std::cout << "Cant Set Year" << std::endl;
        return false;
    }
    this->year = year;
    return true;
}

bool Movie::setDirector(std::string director){
    if ( director == ""){
        std::cout << "Cant Set Director" << std::endl;
        return false;
    }
    this->director = director;
    return true;
}

int Movie::getYear(){
    return year;
}

std::string Movie::getDirector(){
    return director;
}
