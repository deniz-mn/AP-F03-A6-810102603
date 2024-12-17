#include "Food.hpp"

Food :: Food (const string& name_ , int price_): name(name_),price(price_){}
string Food :: get_name(){ return name;}
int Food :: get_price(){ return price;}
