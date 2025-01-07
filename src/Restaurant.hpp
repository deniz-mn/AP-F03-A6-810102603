#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "global.hpp"
#include "Food.hpp"
#include "Reservation.hpp"
#include "Table.hpp"
#include "Exception.hpp"
#include "Discount.hpp"
#include "Person.hpp"

class Restaurant{

public:
	Restaurant(const string& name_,const string& district_,const vector<shared_ptr<Food>>& menu_,
			   int openning_time_,int closing_time_,int num_of_tables_);

	bool is_here(string name_);
	bool is_same_restaurant(shared_ptr<Restaurant>& restaurant);
	bool have_food(string name);
	void print_menu();
	void print_detail();
	void print_total_discount();
	void print_item_discount();
	void print_first_discount();

	vector<shared_ptr<Food>> save_food_in_vector(vector<string>& foods);
	void save_discounts(vector<string> total_discount_input,vector<string> first_order_discount_input,vector<string> item_discount_input);

	bool is_during_operating_hours(int time);
	shared_ptr<Reservation> check_reservation_in_restaurant(int table_id ,int  start_time ,int  end_time ,vector<string> foods , 
																		bool is_first_order,shared_ptr<Person>& login_person);
	shared_ptr<Food>  find_food_by_name(string name);
	


	void print_reservation_id(int id);
	void print_all_reservation();
	int  num_of_reservation();
	void restaurant_delete_reseravtion(int id, shared_ptr<Person>& login_person);
	void print_tables_details();
	
	shared_ptr<Table>  find_reservation_table(int id);


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
	vector<shared_ptr<Table>> tables;
	int reservation_id;


	shared_ptr<Discount> total_discount;
	shared_ptr<Discount> first_order_discount;
	vector<shared_ptr<Discount>> item_discount;
	
};

bool compare_name(shared_ptr<Food>& a ,shared_ptr<Food>& b);
vector<string> save_item_discount(string line);
void print_foods();

#endif