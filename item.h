/**
 * This item class...
 */

#include <string>

#ifndef Item_h
#define Item_h

using namespace std;

class Item {
private:
	int stock;
	string title;

public:
	explicit Item(int, string name);

    virtual ~Item();

	bool setStock(int);

	bool setTitle(string name);

	string getTitle() const;

	int getStock() const;

	friend ostream &operator<<(ostream &os, const Item &i);

	virtual bool operator==(const Item &i) const;
};

#endif /* Item_h */
