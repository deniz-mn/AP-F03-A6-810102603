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
int  Discount :: apply(){
	return 10;
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
int   Item_discount ::   apply(){
	return 100;
}



First_order_discount :: First_order_discount(string type , int value) :  Discount( type , value){}
First_order_discount :: First_order_discount(bool none):Discount(none){}
string  First_order_discount :: get_type(){
	return  get_type_discount();
}
int First_order_discount ::  get_value(){
	return get_value_discount();
}
int First_order_discount :: apply(){
	return 50;
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
int  Total_discount :: apply(){
	return 55;
}