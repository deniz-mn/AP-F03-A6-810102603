#ifndef DISCOUNT_HPP
#define DISCOUNT_HPP

#include "global.hpp"



class Discount {
public:
Discount(string type_ , int value_);
Discount(bool none);
string get_type_discount();
int  get_value_discount();
virtual int apply();

bool is_none();

private:
bool none;
string type;
int value;
};

class Item_discount : public Discount {
public:
Item_discount(string type , int value , string food);
Item_discount(bool none);
string get_type();
int  get_value();
string get_name_food();
int apply();

private:
string food;


};

class First_order_discount : public Discount {
public:
First_order_discount(string type , int value);
First_order_discount(bool none);
string get_type();
int  get_value();
int apply();


private:


};

class Total_discount : public Discount {
public:
Total_discount (string type , int value , int min);
Total_discount(bool none);
string get_type();
int get_min_discount();
int  get_value();
int apply();

private:
int min;


};



#endif