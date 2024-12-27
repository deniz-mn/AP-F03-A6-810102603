#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "global.hpp"
#include "Food.hpp"

class Reservation{

public:
	Reservation(string restaurant_name_,int start_time_,int end_time_,vector<shared_ptr<Food>> ordered_food_, int reserve_id_,int table_id);
	bool is_at_time(int time);

private:
	string restaurant_name;
	int reserve_id;
	int table_number;
	int start_time;
	int end_time;
	vector<shared_ptr<Food>> ordered_food;
};
#endif