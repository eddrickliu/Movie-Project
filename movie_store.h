/**
 * Class that represents the movie store.  The constructor will call one of the
 * main functions where it reads a text file and populates the Movies HashTable
 */

#ifndef ASSIGNMENT4_MOVIE_STORE_H
#define ASSIGNMENT4_MOVIE_STORE_H


#include <map>
#include <vector>
#include "drama.h"
#include "customer.h"
#include "comedy.h"
#include "classic.h"

using namespace std;

class MovieStore {
private:
	//Three different vectors for the three different types of movies
<<<<<<< HEAD
	vector<Drama *> dramas;
	vector<Comedy *> comedies;
=======
	vector<Comedy *> comedies;
	vector<Drama *> dramas;
>>>>>>> master
	vector<Classic *> classics;
	vector<int, Customer *> customers;

	vector<string> split(const string &s, char delim);

public:
	//Constructor for Movie Store, calls the readMovies and readCustomers methods // so that a complete Movie store is created.
	explicit MovieStore();

	~MovieStore();

	//Method that takes in a string that is the file name containing all the the movies
	void readMovies(string fileName);

	//Method that takes in a string that is the file name containing all customers + ID
	void readCustomers(std::string fileName);

	//Method that takes in a string that is the file name containing all commands
	void readCommands(std::string fileName);

	//sorts all Dramas
	void sortDrama();

	//sorts all Comedies
	void sortComedy();

	//sorts all Classics
	void sortClassic();

	// List all the movies
	void inventory() const;

	// List the viewing history of the customer
	void history(int id);

	// Return true if successfully borrow from the movie store
	bool borrowItem(const Customer customer, const Item item);

	// Return true if successfully return to the movie store
	bool returnItem(const Customer customer, const Item item);
};

#endif
