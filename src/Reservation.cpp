#include "Reservation.hpp"

Reservation :: Reservation (string restaurant_name_,int start_time_,int end_time_,vector<shared_ptr<Food>> ordered_food_,
							 int reserve_id_,int table_number_ ,shared_ptr<Discount> total_discount_ ,shared_ptr<Discount> first_order_discount_ ,
							 vector<shared_ptr<Discount>> item_discount_ , bool is_first_order_){
		restaurant_name = restaurant_name_;
		reserve_id = reserve_id_;
		table_number = table_number_ ;
		start_time = start_time_; 			
		end_time = end_time_;
		ordered_food = ordered_food_;
		total_discount = total_discount_;
		first_order_discount = first_order_discount_;
		item_discount = item_discount_ ;
		is_first_order = is_first_order_;
		
}
bool  Reservation :: is_at_start_time(int time){

	return time>=start_time && time<end_time ;
}
bool  Reservation :: is_at_end_time(int time){
	
	return time>start_time && time<=end_time ;
}

int   Reservation :: count_original_price(){
	int original_price = 0;
	for( auto food : ordered_food){
		original_price += food->get_price_food();
	}
	return original_price;
}
shared_ptr<Food>   Reservation :: find_food_by_name(string food_name){
	if(ordered_food.size() > 0){
		for(auto food : ordered_food){
			if(food->is_this_food(food_name))
				return food;
		}
	}
	return nullptr;
}
int   Reservation ::  apply_food_discount(string food_name){
	auto food = find_food_by_name(food_name);

	vector<shared_ptr<Item_discount>> item_discount_ptr ;
	for(auto item : item_discount){
	auto item_ptr = dynamic_pointer_cast<Item_discount>(item);
	if(item_ptr)
		item_discount_ptr.push_back(item_ptr);
	}

	if(item_discount_ptr.size() > 0){
		for(auto item : item_discount_ptr){
			if(item->is_equal(food_name)){
				int after_apply = item->apply(food->get_price_food());
				return after_apply;
			}
		}
	}
	return food->get_price_food();
}
int   Reservation ::  amount_item_discount(int price){
	int price_after_discount = 0 ;
	if(ordered_food.size() > 0){
		for(auto food : ordered_food){
			int after_apply = apply_food_discount(food->get_name_food());
			price_after_discount += after_apply;
		}
		int amount_discount = price - price_after_discount ;
	return amount_discount;
	}
	return 0; 
}
int   Reservation ::   amount_total_discount(int price){

	int after_apply = total_discount->apply(price);
	int amount = price - after_apply ;
	return amount;
}
int   Reservation ::  amount_first_discount(int price){
	if(!is_first_order)
		return 0;

	int after_apply = first_order_discount->apply(price);
	int amount = price - after_apply ;
	return amount;
}
int   Reservation ::  get_final_price(){
	int original_price = count_original_price();
	int price_after_item_discount = original_price - amount_item_discount( original_price );
	int price_after_first_discount = price_after_item_discount - amount_first_discount( price_after_item_discount );
	int price_after_total_discount = price_after_first_discount -  amount_total_discount(price_after_first_discount);
	int amount_discount = amount_item_discount( original_price ) + amount_first_discount( price_after_item_discount )
								+ price_after_first_discount -  amount_total_discount(price_after_first_discount);

	int final_price = original_price - amount_discount ;
	return final_price;

}
void  Reservation ::  print_reservation_req(){

	int original_price = count_original_price();
	int price_after_item_discount = original_price - amount_item_discount( original_price );
	int price_after_first_discount = price_after_item_discount - amount_first_discount( price_after_item_discount );
	int price_after_total_discount = price_after_first_discount -  amount_total_discount(price_after_first_discount);
	int amount_discount = amount_item_discount( original_price ) + amount_first_discount( price_after_item_discount )
								+ price_after_first_discount -  amount_total_discount(price_after_first_discount);
	int final_price = original_price - amount_discount ;

	

	cout<<"Reserve ID: "<<reserve_id <<endl;
	cout<<"Table "<<table_number<<" for "<<start_time<<" to "<<end_time<<" in "<<restaurant_name<<endl;
	cout<<"Original Price: "<<original_price<<endl;
	cout<<"Order Amount Discount: "<< amount_total_discount(price_after_first_discount)<<endl;
	cout<<"Total Item Specific Discount: "<<amount_item_discount( original_price )<<endl;
	cout<<"First Order Discount: "<< amount_first_discount( price_after_item_discount )<<endl;
	cout<<"Total Discount: "<<amount_discount <<endl;
	cout<<"Total Price: "<<final_price<<endl;
}
int   Reservation ::  get_start(){
	return start_time;
}
int   Reservation ::  get_end(){
	return end_time;
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
	}
	cout<<count_original_price()<<" "<<get_final_price()<<endl;

}

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
int  Reservation  ::  get_reservation_id(){
	return reserve_id ;
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