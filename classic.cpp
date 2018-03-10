// Implementation of classic.h

#include "classic.h"

<<<<<<< HEAD
Classic::Classic(int stock, std::string director, std::string title,
                 std::string actor, int month, int year) : Movie(year, director, title, stock){
    
=======
explicit Classic(int stock, std::string director, std::string title,
                 std::string actor, int month, int year) :
Movie(year, director, title, stock ){
    setActor(actor);
    setMonth(month);
>>>>>>> master
}

Classic::~Classic() {

}

bool setActor(std::string actor) {
    if ( actor  == ""){
        std::cout << "Cant Set Actor" << std::endl;
        return false;
    }
    this->actor  = actor;
    return true;
}

string getActor() {
    return actor;
}

bool setMonth(int month) {
    if ( month > 12 || month < 1){
        std::cout << "Cant Set Month" << std::endl;
        return false;
    }
    this->month  = month;
    return true;
}

int getMonth() {
    return month;
}

ostream &operator<<(ostream &os, const Item &i) {
    os << i.year << i.director << i.title << i.stock << i.actor << i.swagger;
    return os
}

istream &operator>>(istream &is, Item &i) {
    is >> i.year >> i.director >> i.title >> i.stock;
    return is;
}

bool Classic::operator==(const Item &i) const {

<<<<<<< HEAD
=======
    return Movie::operator==(i);
>>>>>>> master
}
