#include "Reservation.hpp"

Reservation :: Reservation (string restaurant_name_,int start_time_,int end_time_,vector<shared_ptr<Food>> ordered_food_, int reserve_id_,int table_number_ ){
		restaurant_name = restaurant_name_;
		reserve_id = reserve_id_;
		table_number = table_number_ ;
		start_time = start_time_; 			
		end_time = end_time_;
		ordered_food = ordered_food_;
}
bool  Reservation :: is_at_time(int time){
	return time>start_time && time<end_time ;
}