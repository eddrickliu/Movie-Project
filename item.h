//
//  Item.h
//  Ass4
//
//  Created by Eddrick Liu on 3/7/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

#include <string>

#ifndef Item_h
#define Item_h

class Item {
private:
	int stock; // >0
	std::string title; // Null check
public:
	explicit Item(int, std::string name);

	~Item();

	bool setStock(int);

	bool setTitle(std::string name);

	std::string getTitle();

	int getStock();

	friend std::ostream &operator<<(std::ostream &os, const Item &i);

	friend std::istream &operator>>(std::istream &is, Item &i);

	virtual bool operator==(const Item &i) const;
};

#endif /* Item_h */
