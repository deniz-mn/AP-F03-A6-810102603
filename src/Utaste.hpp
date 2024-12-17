#ifndef UTASTE_HPP
#define UTASTE_HPP

#include "global.hpp"
#include "Person.hpp"
#include "Restaurant.hpp"
#include "Neighborhood.hpp"

class Utaste{

public:
	Utaste();
	~Utaste();
	void save_restaurant_input(const string& file_name);
	void save_neighbors_input(const string& file_name);
	//void login(string username , string password);
	void signup (string& username , string& password);
	void print();

private:
	vector<shared_ptr<Person>> persons;
	vector<shared_ptr<Restaurant>> restaurants;
	vector<shared_ptr<Neighborhood>> neighborhoods;

};

vector<string> file_reader (string file_name);
vector<string> string_seprator(string line , char seprator);
vector<shared_ptr<Food>> save_menu (string input);
#endif