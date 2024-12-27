#ifndef FOOD_HPP
#define FOOD_HPP

#include "global.hpp"

class Food{

public:
	Food (const string& name_ , int price_);
	Food (const string& name_ );

	bool is_this_food(string name_);
	string get_name_food();
	int get_price_food();
private:
	string name;
	int price;
};
#endif