/**
 * Implementation of comedy.h
 */

#include "comedy.h"

Comedy::Comedy(int stock, string director, string title, int year) :
        Movie(year, director, title, stock) {
    // No need to do anything here
}
bool Comedy::operator>(const Comedy &c) const{
    if (this->getTitle() < c.getTitle()){
        return false;
    }
    else if (this->getYear() < c.getYear()){
        return false;
    }
    return true;
}

bool Comedy::operator<(const Comedy &c) const{
    if (this->getTitle() > c.getTitle()){
        return false;
    }
    else if (this->getYear() > c.getYear()){
        return false;
    }
    return true;
}
