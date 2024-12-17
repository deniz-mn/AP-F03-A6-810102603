#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "global.hpp"
#include "Food.hpp"
#include "Reservation.hpp"
#include "table.hpp"

class Restaurant{

public:
	Restaurant(const string& name_,const string& district_,
			   const vector<shared_ptr<Food>>& menu_,int openning_time_,
			   int closing_time_,int num_of_tables_);
	int get_openning ();
	string get_name();
	void get_menu();
private:
	string name;
	string district;
	vector<shared_ptr<Food>> menu;
	int openning_time;
	int closing_time;
	int num_of_tables;
	//vector<shared_ptr<table>> tables;
	//vector<reservation> reservations;
	//vector<int> reservation_id;

	
};

#endif