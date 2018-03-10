// Implementation of movie_store.h

#include "movie_store.h"
#include<iostream>
#include<fstream>
#include <sstream>

MovieStore::MovieStore() {

}

MovieStore::~MovieStore() {
	dramas.clear();
	comedies.clear();
	classics.clear();

	delete dramas;
	delete comedies;
	delete classics;
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
		int stock = stoi(movieInfo[1]);

		if (movieInfo[0] == 'F') {
			int year = stoi(line.substr(line.length() - 4));
			comedy *f = new comedy(movieInfo[2], movieInfo[3], stock, year);
			comedies.push_back(f);
		} else if (movieInfo[0] == 'D') {
			int year = stoi(line.substr(line.length() - 4));
			drama *d = new drama(movieInfo[2], movieInfo[3], stock, year);
			dramas.push_back(d);
		} else if (movieInfo[0] == 'C') {
			vector<string> classicInfo = split(movieInfo[4], ' ');
			int month = stoi(classicInfo[1]);
			int year = stoi(classicInfo[2]);
			Classic *c = new Classic(movieInfo[2], movieInfo[3], stock,
			                         classicInfo[0], year, month);
			classics.push_back(c);
		}
	}
}

//Method that takes in a string that is the file name containing all customers + ID
void MovieStore::readCustomers(string fileName) {
	ifstream infile(fileName);
	string line;
	while (infile >> line) {

		vector<string> customerInfo = split(line, ' ');
		int id = stoi(customerInfo[0]);
		Customer *c = new Customer(id, customerInfo[1], customerInfo[2]);
		// TODO add customers to hash table
		customers.push_back(id, c);
	}
}

//Method that takes in a string that is the file name containing all commands
void MovieStore::readCommands(string fileName) {
    string line,command,dvd,movieType;
    int id;
    
        ifstream myfile(fileName);
        if (!myfile)  // Check if can open the file
        {
            cout << "Can't open the file\n";
        }
        
        while (myfile.good())  // Get next line
        {
            myfile>>command;
            if(command == "I"){
                inventory();
            }
            else if(command == "H"){
                myfile>>id;
                hitory(id);
            }
            else if(command == "B"){
                myfile>>id>>dvd>>movieType;
                borrowItem(id, )
            }
            else if(command == "R"){
                returnItem(id, )
            }
            else{
                cout<<"Bad input!";
            }
            
            
        }
        myfile.close(); // Close input file stream
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
void MovieStore::inventory() const {
	for (auto const &value: dramas) cout << value->getTitle();
	for (auto const &value: comedies) cout << value->getTitle();
	for (auto const &value: classics) cout << value->getTitle();
}

// List the viewing history of the customer
void MovieStore::history(int id) {
	// TODO FIXME
	for (auto &customer : customers) {
		customer.iterateHistory();
	}
}

// Return true if successfully borrow from the movie store
bool MovieStore::borrowItem(const Customer customer, const Item item) {
	customer.borrowItem(item);
}

// Return true if successfully return to the movie store
bool MovieStore::returnItem(const Customer customer, const Item item) {
	customer.returnItem(item);
}
