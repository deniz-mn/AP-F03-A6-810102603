#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "global.hpp"
#include "food.hpp"

class reservation{

public:

private:
	string restaurant_name;
	int table_number;
	int start_time;
	int end_time;
	vector<food> ordered_food;
};
#endif