// Implementation of classic.h

#include "classic.h"

Classic::Classic(int stock, std::string director, std::string title,
                 std::string actor, int month, int year) : Movie(year, director, title, stock){
    
}

Classic::~Classic() {

}

bool setActor(std::string) {

}

string getActor() {

}

bool setMonth(int) {

}

int getMonth() {

}

ostream &operator<<(ostream &os, const Item &i) {

}

istream &operator>>(istream &is, Item &i) {

}

bool Classic::operator==(const Item &i) const {

}
