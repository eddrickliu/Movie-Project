/**
 * Implementation of item.h
 */

#include "item.h"
#include <iostream>

Item::Item(int stock, string title) {
	setStock(stock);
	setTitle(title);
}

bool Item::setStock(int stock) {
	if (stock < 0) {
		cout << "Cant Set Stock" << endl;
		return false;
	}
	this->stock = stock;
	return true;
}

bool Item::setTitle(string title) {
	if (title.empty()) {
		cout << "Cant Set Title" << endl;
		return false;
	}
	this->title = title;
	return true;
}

int Item::getStock() const {
	return stock;
}

string Item::getTitle() const {
	return title;
}

ostream &operator<<(ostream &os, const Item &i) {
	os << i.getTitle() << i.getStock();
	return os;
}

istream &operator>>(istream &is, Item &i) {
//	is >> i.title >> i.stock;
	return is;
}

bool Item::operator==(const Item &i) const {
	return (this->title == i.title);
}
