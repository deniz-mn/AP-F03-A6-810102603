#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "global.hpp"
#include "Food.hpp"

class Reservation{

public:

private:
	string restaurant_name;
	int table_number;
	int start_time;
	int end_time;
	vector<Food> ordered_food;
};
#endif