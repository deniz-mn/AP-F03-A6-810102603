#ifndef FOOD_HPP
#define FOOD_HPP

#include "global.hpp"

class Food{

public:
	Food (const string& name_ , int price_);
	string get_name();
	int get_price();
private:
	string name;
	int price;
};
#endif