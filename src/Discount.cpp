#include "Discount.hpp"

Discount :: Discount (string type , int value): type(type) , value(value), none(false){}
Discount :: Discount(bool none):none(none), type(""), value(0) {}

bool Discount :: is_none(){
	return none;
}

Item_discount :: Item_discount ( string type , int value , string food): Discount( type , value) , food(food){}
Item_discount :: Item_discount (bool none):Discount(none), food(""){}

First_order_discount :: First_order_discount(string type , int value) :  Discount( type , value){}
First_order_discount :: First_order_discount(bool none):Discount(none){}

Total_discount :: Total_discount  (string type , int value , int min) :  Discount( type , value) , min(min){}
Total_discount :: Total_discount (bool none):Discount(none), min(0){}
