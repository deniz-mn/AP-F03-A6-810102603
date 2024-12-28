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
	return time>=start_time && time<=end_time ;
}
void  Reservation ::  print_reservation_req(){
	cout<<" omadam ke print konam hamarooo"<<endl;
	cout<<"Reserve ID: "<<reserve_id <<endl;
	cout<<"Table "<<table_number<<" for "<<start_time<<" to "<<end_time<<" in "<<restaurant_name<<endl;
	int total_cost = total_price();
	cout<<"Price: "<<total_cost<<endl;
}
int   Reservation :: total_price(){
	int total_price = 0;
	for( auto food : ordered_food){
		total_price += food->get_price_food();
	}
	return total_price;
}