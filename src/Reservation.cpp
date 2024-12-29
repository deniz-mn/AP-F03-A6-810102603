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
int   Reservation ::  get_start(){
	return start_time;
}
bool  Reservation :: is_equal(int id){
	if(reserve_id == id)
		return true;
	return false;
}
void  Reservation :: print_in_line(){

	cout<<reserve_id<<": "<<restaurant_name<<" "<<table_number<<" "<<start_time<<"-"<<end_time<<" ";
	if( ordered_food.size() > 0){
		print_foods( );
		cout<<endl;
	}
}
// bool  Reservation :: compare_name(const shared_ptr<Food>& a ,const shared_ptr<Food>& b){
// 	return a->get_name_food()[0] < b->get_name_food()[0] ;
// }
void  Reservation :: print_foods(){

	sort(ordered_food.begin() , ordered_food.end() , [](const std::shared_ptr<Food>& a, const std::shared_ptr<Food>& b) { return a->get_name_food() < b->get_name_food(); });
	int counter = 1;
	for(int i=0 ; i<ordered_food.size()-1 ; i++){

		if(ordered_food[i]->get_name_food() != ordered_food[i+1]->get_name_food()){
			cout<<ordered_food[i]->get_name_food()<<"("<<counter<<")"<<" ";
			counter = 1 ;
		}
		else{
			counter ++;
		}
	}
}
string   Reservation  :: get_name_restaurant(){
	return restaurant_name;
}
int      Reservation  :: get_time(){
	return start_time;
}
bool   Reservation  :: has_reserve_id(int id){
	return reserve_id = id;
}