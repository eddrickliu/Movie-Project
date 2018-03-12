// Implementation of movie_store.h

#include "movie_store.h"
#include<iostream>
#include<fstream>
#include<sstream>

MovieStore::MovieStore() {

}

MovieStore::~MovieStore() {
    for ( auto & item : dramas){
        delete item;
    }
    for ( auto & item : comedies){
        delete item;
    }
    for ( auto & item : classics){
        delete item;
    }

    for ( auto & bucket : customers){
        for ( auto & item : bucket){
            delete item;
        }
        bucket.clear();
    }

	dramas.clear();
	comedies.clear();
	classics.clear();

	//delete dramas;
	//delete comedies;
	//delete classics;
}

vector<string> MovieStore::split(const string &s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}

// Method that takes in a string that is the file name containing all the the
// movies
void MovieStore::readMovies(string fileName) {
	ifstream infile(fileName);
	string line;
	while (infile >> line) {

		vector<string> movieInfo = split(line, ',');
		cout << movieInfo[1];
		int stock = stoi(movieInfo[1]);

		if (movieInfo[0] == "F") {
			int year = stoi(line.substr(line.length() - 4));
			Comedy *f = new Comedy(stock, movieInfo[2], movieInfo[3], year);
			comedies.push_back(f);
		} else if (movieInfo[0] == "D") {
			int year = stoi(line.substr(line.length() - 4));
			Drama *d = new Drama(stock, movieInfo[2], movieInfo[3], year);
			dramas.push_back(d);
		} else if (movieInfo[0] == "C") {
			vector<string> classicInfo = split(movieInfo[4], ' ');
			int month = stoi(classicInfo[1]);
			int year = stoi(classicInfo[2]);
			Classic *c = new Classic(stock, movieInfo[2], movieInfo[3],
			                         classicInfo[0], month, year);
			classics.push_back(c);
		}
	}
	sortDrama();
	sortComedy();
	sortClassic();
}

//Method that takes in a string that is the file name containing all customers + ID
void MovieStore::readCustomers(string fileName) {
	ifstream infile(fileName);
	string line;
	while (infile >> line) {

		vector<string> customerInfo = split(line, ' ');
		//int id = stoi(customerInfo[0]);
		Customer *c = new Customer(customerInfo[0], customerInfo[1],
		                           customerInfo[2]);
		// TODO add customers to hash table
		addCustomer(c);
	}
}

//Method that takes in a string that is the file name containing all commands
void MovieStore::readCommands(string fileName) {
	ifstream myfile(fileName);
	string line;

	if (!myfile)  // Check if can open the file
	{
		cout << "Can't open the file\n";
		return;
	}

	while (myfile >> line) {
		//vector<string> movieInfo = split(line, ' ');
		//string line,command,dvd,movieType;
		//string id;
		//ifstream myfile(fileName);
		//myfile>>command;
		if (line.substr(0, 1) == "I") { // No more field after I
			inventory();
		} else if (line.substr(0, 1) == "H") { // H & customer ID
			// Take in customer ID & List transcation history
			// Check if the customer exist first
			if (!history(line.substr(2, 4))) {
				cout << "Customer not found" << endl;
			}
		} else if ((line.substr(0, 1) == "B" || line.substr(0, 1) == "R") &&
		           line.substr(7, 1) == "D") {
			if (line.substr(9, 1) == "F") {
				vector<string> movieInfo = split(
						line.substr(11, line.size() - 11), ',');
				if (line.substr(0, 1) == "B") {
					if (!borrowItem(line.substr(2, 4),
					                searchComedy(movieInfo[0],
					                             stoi(movieInfo[1])))) {
						cout << "Bad input!" << endl;
					}
				} else {
					if (!returnItem(line.substr(2, 4),
					                searchComedy(movieInfo[0],
					                             stoi(movieInfo[1])))) {
						cout << "Bad input!" << endl;
					}
				}
			}
			if (line.substr(9, 1) == "D") {
				vector<string> movieInfo = split(
						line.substr(11, line.size() - 11), ',');
				if (line.substr(0, 1) == "B") {
					if (!borrowItem(line.substr(2, 4),
					                searchDrama(movieInfo[0], movieInfo[1]))) {
						cout << "Bad input!" << endl;
					}
				} else {
					if (!returnItem(line.substr(2, 4),
					                searchDrama(movieInfo[0], movieInfo[1]))) {
						cout << "Bad input!" << endl;
					}
				}
			}
			if (line.substr(9, 1) == "C") {
				//vector<string> movieInfo = split(line.substr(11, line.size()),',');
				if (line.substr(0, 1) == "B") {
					if (!borrowItem(line.substr(2, 4), searchClassic(
							line.substr(18, line.size() - 18),
							stoi(line.substr(11, 1)),
							stoi(line.substr(13, 4))))) {
						cout << "Bad input!" << endl;
					}
				} else {
					if (!returnItem(line.substr(2, 4), searchClassic(
							line.substr(18, line.size() - 18),
							stoi(line.substr(11, 1)),
							stoi(line.substr(13, 4))))) {
						cout << "Bad input!" << endl;
					}
				}
			}
		} else { // Bad input
			cout << "Bad input!" << endl;
		}
		myfile.close(); // Close input file stream
	}
}

//TODO: Search classic(string title, string director) // check both ways director and title

Classic *MovieStore::searchClassic(string s, int month, int year) {
	for (auto &classic : classics) {
		if ((s == classic->getActor() || s == classic->getDirector()) &&
		    month == classic->getMonth() && year == classic->getYear()) {
			return classic;
		}
	}
	return nullptr;
}


Comedy *MovieStore::searchComedy(string s, int year) {
	for (auto &comedy : comedies) {
		if (s == comedy->getTitle() && year == comedy->getYear()) {
			return comedy;
		} else if (s == comedy->getDirector() && year == comedy->getYear()) {
			return comedy;
		}
	}
	return nullptr;
}

Drama *MovieStore::searchDrama(string s, string s1) {
	for (auto &drama : dramas) {
		if (s == drama->getTitle() && s1 == drama->getDirector()) {
			return drama;
		} else if (s == drama->getDirector() && s1 == drama->getTitle()) {
			return drama;
		}
	}
	return nullptr;
}

//sorts all Dramas
void MovieStore::sortDrama() {
	sort(dramas.begin(), dramas.end());
}

//sorts all Comedies
void MovieStore::sortComedy() {
	sort(classics.begin(), classics.end());
}

//sorts all Classics
void MovieStore::sortClassic() {
	sort(classics.begin(), classics.end());
}

// List all the movies
// Sort the movies before output to the screen
void MovieStore::inventory() {
	sortDrama();
	sortComedy();
	sortClassic();
	for (auto const &value: comedies) {
		if (value->getStock() > 0) {
			cout << value->getTitle();
		}
	}
	for (auto const &value: dramas) {
		if (value->getStock() > 0) {
			cout << value->getTitle();
		}
	}
	for (auto const &value: classics) {
		if (value->getStock() > 0) {
			cout << value->getTitle();
		}
	}
}

// List the viewing history of the customer
// Return true if the customer exit
// Otherwise return false
bool MovieStore::history(string id) {
	// Fixed
	Customer *cust = accessCustomer(id);
	if (cust) {
		cust->iterateHistory();
		return true;
	}
	return false;
}

// Return true if successfully borrow from the movie store
// Check if the movie is in stock
// Return false if the movie is unavailable
bool MovieStore::borrowItem(string ID, Item *item) {
	for (auto &com : comedies) {
		if (com == item && com->getStock() > 0) {
			com->setStock(com->getStock() - 1);
			return accessCustomer(ID)->borrowItem(item);
		}
	}
	for (auto &dra : dramas) {
		if (dra == item && dra->getStock() > 0) {
			dra->setStock(dra->getStock() - 1);
			return accessCustomer(ID)->borrowItem(item);
		}
	}
	for (auto &clas : classics) {
		if (clas == item && clas->getStock() > 0) {
			clas->setStock(clas->getStock() - 1);
			return accessCustomer(ID)->borrowItem(item);
		}
	}
	return false; // Item unavailable or stock = 0
}

// Return true if successfully return to the movie store
//
bool MovieStore::returnItem(string ID, Item *item) {
	for (auto &com : comedies) {
		if (com == item) {
			com->setStock(com->getStock() + 1);
			return accessCustomer(ID)->returnItem(item);
		}
	}
	for (auto &dra : dramas) {
		if (dra == item) {
			dra->setStock(dra->getStock() + 1);
			return accessCustomer(ID)->returnItem(item);
		}
	}
	for (auto &clas : classics) {
		if (clas == item) {
			clas->setStock(clas->getStock() + 1);
			return accessCustomer(ID)->returnItem(item);
		}
	}
	return false; // The movie doesn't exit
}

int MovieStore::Hash(string key) {
	int hash = 0;
	int index;

    for (auto const &value: key){
        hash += (int)value;
    }

	index = hash % 10;
	return index;
}

void MovieStore::addCustomer(Customer *c) {
	int index = Hash(c->getID());
	customers[index].push_back(c);
}

Customer *MovieStore::accessCustomer(string ID) {
	int index = Hash(ID);
	for (auto const &value: customers[index]) {
		if (value->getID() == ID) {
			return value;
		}
	}
	return nullptr;
}
