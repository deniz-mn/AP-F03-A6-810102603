#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "global.hpp"
#include "food.hpp"
#include "reservation.hpp"
#include "table.hpp"

class restaurant{

public:

private:
	string name;
	string district;
	vector<food> menu;
	int closing_time;
	int openning_time;
	vector<table> tables;
	vector<reservation> reservations;
	vector<int> reservation_id;

	
}

#endif