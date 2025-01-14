#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "global.hpp"
#include "Food.hpp"
#include "Discount.hpp"



class Reservation{

public:
	Reservation(string restaurant_name_,int start_time_,int end_time_,vector<shared_ptr<Food>> ordered_food_, int reserve_id_,int table_id
				,shared_ptr<Discount> total_discount_ ,shared_ptr<Discount> first_order_discount_ ,vector<shared_ptr<Discount>> item_discount_
				, bool is_first_order_ );

	bool is_at_start_time(int time);
	bool is_at_end_time(int time);
	void print_reservation_req();
	int  count_original_price();
	void print_foods(ostream& out);
	int  get_start();
	int    get_end();
	bool is_equal(int id);
	string get_name_restaurant();
	bool  has_reserve_id(int id);
	void print_in_line(ostream& out);
	int  get_time();
	int get_reservation_id();
	int get_final_price();
	shared_ptr<Food>  find_food_by_name(string food_name);
	int  apply_food_discount(string food_name);
	int  amount_item_discount(int price);
	int  amount_total_discount(int price);
	int  amount_first_discount(int price);


private:
	string restaurant_name;
	int reserve_id;
	int table_number;
	int start_time;
	int end_time;
	vector<shared_ptr<Food>> ordered_food;
	bool is_first_order;

	shared_ptr<Discount> total_discount ;
	shared_ptr<Discount> first_order_discount;
	vector<shared_ptr<Discount>> item_discount;
};


#endif