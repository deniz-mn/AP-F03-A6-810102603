#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "global.hpp"
#include "Food.hpp"
#include "Reservation.hpp"
#include "table.hpp"

class Restaurant{

public:
	Restaurant(const string& name_,const string& district_,const vector<shared_ptr<Food>>& menu_,
			   int openning_time_,int closing_time_,int num_of_tables_);

	bool is_here(string name_);
	bool is_same_restaurant(shared_ptr<Restaurant>& restaurant);
	bool have_food(string name);
	void print_menu();
	void print_detail();

	void print_name_district();
	int get_openning ();
	string get_name_restaurant();
private:
	string name;
	string district ;
	vector<shared_ptr<Food>> menu;
	int openning_time;
	int closing_time;
	int num_of_tables;
	//vector<shared_ptr<table>> tables;
	//vector<reservation> reservations;
	//vector<int> reservation_id;

	
};

bool compare_name(shared_ptr<Food>& a ,shared_ptr<Food>& b);

#endif