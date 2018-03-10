//
//  Item.cpp
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

#include "item.h"
#include <iostream>
#include <stdio.h>
#include <string>

/*
 
 */
Item::Item(int stock, std::string title) {
	setStock(stock);
	setTitle(title);
}

/*
 
 */
Item::~Item() {

}

/*
 
 */
bool Item::setStock(int stock) {
	if (stock < 0) {
		std::cout << "Cant Set Stock" << std::endl;
		return false;
	}
	this->stock = stock;
	return true;
}

/*
 
 */
bool Item::setTitle(std::string title) {
	if (title == "") {
		std::cout << "Cant Set Title" << std::endl;
		return false;
	}
	this->title = title;
	return true;
}

/*
 *
 */
int Item::getStock() const {
	return stock;
}

/*
 
 */
std::string Item::getTitle() const {
	return title;
}

/*
 
 */
std::ostream &operator<<(std::ostream &os, const Item &i) {
	os << i.title << i.stock;
	return os;
}

/*
 
 */
std::istream &operator>>(std::istream &is, Item &i) {
	is >> i.title >> i.stock;
	return is;
}
