#include "Discount.hpp"

Discount :: Discount (string type_ , int value_): value(value_), type(type_), none(false){
	if(type_ == "percent")
		type = "percentage";
	if(type_ == "amount")
		type = "amount";
}
Discount :: Discount(bool none):none(none), type(""), value(0) {}
string  Discount ::get_type_discount(){
	return type;
}
bool Discount :: is_none(){
	return none;
}
int  Discount :: get_value_discount(){
	return value;
}
// int  Discount :: apply(){
// 	return 0;
// }
int  Discount :: calculate_discount(int price){
	if( type == "percentage" ){
		int final_price = price - (  value*total_price / 100 );
		return final_price;
	}
	else if( type == "amount" ){
		int final_price = price - value;
		return final_price;
	}
return ;
}





Item_discount :: Item_discount ( string type , int value , string food): Discount( type , value) , food(food){}
Item_discount :: Item_discount (bool none):Discount(none), food(""){}
string Item_discount :: get_type(){
	return  get_type_discount();
}
int Item_discount ::  get_value(){
	return get_value_discount();
}
string  Item_discount ::  get_name_food(){
	return food ;
}
bool  Item_discount ::   is_equal(string food_name){
	if(food_name == food)
		return true;
	return false;
}
int  Item_discount ::   apply(int price){
	if(is_none())
		return price;

	int final_price = calculate_discount(price);

	return final_price;
}



First_order_discount :: First_order_discount(string type , int value) :  Discount( type , value){}
First_order_discount :: First_order_discount(bool none):Discount(none){}
string  First_order_discount :: get_type(){
	return  get_type_discount();
}
int First_order_discount ::  get_value(){
	return get_value_discount();
}
int First_order_discount ::  apply(int price){
	if(is_none())
		return total_price;

	int final_price = calculate_discount(total_price);
	return final_price;
}



Total_discount :: Total_discount  (string type , int value , int min) :  Discount( type , value) , min(min){}
Total_discount :: Total_discount (bool none):Discount(none), min(0){}
string  Total_discount :: get_type(){
	return  get_type_discount();
}
int   Total_discount :: get_min_discount(){
	return min;
}
int   Total_discount ::  get_value(){
	return get_value_discount();
}
int   Total_discount :: apply(int total_price){
	if(is_none())
		return total_price;
	else if(total_price < min)
		return total_price;
	esle{
		int final_price = calculate_discount(total_price);
		return final_price;
	}
}