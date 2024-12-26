#include "Food.hpp"

Food :: Food (const string& name_ , int price_): name(name_),price(price_){}
string Food :: get_name_food(){ return name;}
int    Food :: get_price_food(){ return price;}

bool   Food ::is_this_food(string name_){
	if(name == name_)
		return true;
	return false;
}
