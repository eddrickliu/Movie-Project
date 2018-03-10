// Implementation of classic.h

#include "classic.h"

explicit Classic::Classic(int stock, std::string director, std::string title,
                 std::string actor, int month, int year) :
Movie(year, director, title, stock ){
    setActor(actor);
    setMonth(month);
}

Classic::~Classic() {

}

bool Classic::setActor(std::string actor) {
    if ( actor  == ""){
        std::cout << "Cant Set Actor" << std::endl;
        return false;
    }
    this->actor  = actor;
    return true;
}

string Classic::getActor() {
    return actor;
}

bool Classic::setMonth(int month) {
    if ( month > 12 || month < 1){
        std::cout << "Cant Set Month" << std::endl;
        return false;
    }
    this->month  = month;
    return true;
}

int Classic::getMonth() {
    return month;
}

ostream Classic::&operator<<(ostream &os, const Item &i) {
    os << i.year << i.director << i.title << i.stock << i.actor << i.swagger;
    return os;
}

istream Classic::&operator>>(istream &is, Item &i) {
    is >> i.year >> i.director >> i.title >> i.stock;
    return is;
}

bool Classic::operator==(const Classic &c) const {

    if (Movie::operator==(c) == false) {
        return false;
    }
    return ( this->month == m.month) &&  ( this->actor == m.actor);
}
