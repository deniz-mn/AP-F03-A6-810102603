#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "global.hpp"
#include "food.hpp"

class{

public:

private:
	restaurant_name;
	table_number;
	start_time;
	end_time;
	vector<food> ordered_food;
};
#endif