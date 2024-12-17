#ifndef NEIGHBORHOOD_HPP
#define NEIGHBORHOOD_HPP

#include "global.hpp"



class Neighborhood{

public:
	Neighborhood (string name_,vector<string> neighbors_);

	void print();
private:
	string name;
	vector<string> neighbors;
	//vector<string> neighbor_restaurant;
};

#endif