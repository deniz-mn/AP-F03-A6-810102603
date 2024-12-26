#ifndef NEIGHBORHOOD_HPP
#define NEIGHBORHOOD_HPP

#include "global.hpp"



class Neighborhood{

public:
	Neighborhood (string name_,vector<string> neighbors_);
	bool is_equal(string name_);
	void print_neighbors();

	string get_name_district();
	vector<string> get_neighbors();
	

	void print();
private:
	string name;
	vector<string> neighbors;
	//vector<string> neighbor_restaurant;
};


void   print_vector_with_seprator(vector<string>neighbors , char seprator);


#endif