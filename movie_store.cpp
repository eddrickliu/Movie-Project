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
		int stock = stoi(movieInfo[1]);

		if (movieInfo[0] == "F") {
			int year = stoi(line.substr(line.length() - 4));
			Comedy *f = new Comedy(stock,movieInfo[2], movieInfo[3], year);
			comedies.push_back(f);
		} else if (movieInfo[0] == "D") {
			int year = stoi(line.substr(line.length() - 4));
			Drama *d = new Drama(stock,movieInfo[2], movieInfo[3], year);
			dramas.push_back(d);
		} else if (movieInfo[0] == "C") {
			vector<string> classicInfo = split(movieInfo[4], ' ');
			int month = stoi(classicInfo[1]);
			int year = stoi(classicInfo[2]);
			Classic *c = new Classic(stock,movieInfo[2], movieInfo[3],
			                         classicInfo[0], month, year);
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
		//int id = stoi(customerInfo[0]);
		Customer *c = new Customer(customerInfo[0], customerInfo[1], customerInfo[2]);
		// TODO add customers to hash table
		addCustomer(c);
	}
}

//Method that takes in a string that is the file name containing all commands
void MovieStore::readCommands(string fileName) {
    string line,command,dvd,movieType;
    string id;
    
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
                history(id);
            }
            else if(command == "B"){
                myfile>>id>>dvd>>movieType;
                //borrowItem(id, );
            }
            else if(command == "R"){
                //returnItem(id, );
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
void MovieStore::history(string id) {
	// TODO FIXME
	for ( int i = 0; i < customers.size();i++) {
		for (auto &customer : customers[i]) {
			customer->iterateHistory();
		}
	}
}

// Return true if successfully borrow from the movie store
bool MovieStore::borrowItem(string ID, Item *item) {
	if(accessCustomer(ID)->borrowItem(item)){
		return true;
	}
	return false;
}

// Return true if successfully return to the movie store
bool MovieStore::returnItem(string ID, Item *item) {
	if(accessCustomer(ID)->returnItem(item)){
		return true;
	}
	return false;
}

int MovieStore::Hash(string key){
	int hash = 0;
	int index;

	for(int i = 0; i < key.size(); i++){
		hash += (int)key[i];
	}

	index = hash % 10;
	return index;
}

void MovieStore::addCustomer(Customer *c){
	int index = Hash(c->getID());
	customers[index].push_back(c);
}

Customer* MovieStore::accessCustomer(string ID){
	int index = Hash(ID);
//	for (int i = 0; i < customers[index].size(); i++){
//		if (customers[index]
//	}
//	for(vector<Customer*>::iterator it = customers[index].begin(); it != end; ++it){
//		if(it->getId== c->getID())
//	}
	for(auto const& value: customers[index]){
		if(value->getID()==ID){
			return value;
		}
	}
	return nullptr;
}

Classic* MovieStore::searchClassic(string director, int year){
	for (auto &classic : classics) {
		if( title == classic->getDirector() && year == classic->getYear() ){
			return classic;
		}
	}
}
Comedy* MovieStore::searchComedy(string director, int year){
	for (auto &comedy : comedies) {
		if( title == comedy->getDirector() && year == comedy->getYear() ){
			return comedy;
		}
	}
}
Drama* MovieStore::searchDrama(string director, int year){
	for (auto &drama : dramas) {
		if( title == drama->getDirector() && year == drama->getYear() ){
			return drama;
		}
	}
}