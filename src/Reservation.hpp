#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "global.hpp"
#include "Food.hpp"
#include "Discount.hpp"


class Reservation{

public:
	Reservation(string restaurant_name_,int start_time_,int end_time_,vector<shared_ptr<Food>> ordered_food_, int reserve_id_,int table_id
				,shared_ptr<Discount> total_discount_ ,shared_ptr<Discount> first_order_discount_ ,vector<shared_ptr<Discount>> item_discount_ );

	bool is_at_start_time(int time);
	bool is_at_end_time(int time);
	void print_reservation_req();
	int  original_price();
	void print_foods();
	int  get_start();
	int    get_end();
	bool is_equal(int id);
	string get_name_restaurant();
	bool  has_reserve_id(int id);
	void print_in_line();
	int  get_time();
	int get_reservation_id();
	//bool compare_name(const shared_ptr<Food>& a , const shared_ptr<Food>& b);
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