#ifndef DISCOUNT_HPP
#define DISCOUNT_HPP

#include "global.hpp"



class Discount {
public:
Discount(string type_ , int value_);
Discount(bool none);
string get_type_discount();
int  get_value_discount();

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
virtual ~Discount() = default;
virtual string get_type();
virtual int  get_value();
virtual string get_name_food();

private:
string food;


};

class First_order_discount : public Discount {
public:
First_order_discount(string type , int value);
First_order_discount(bool none);
string get_type();
int  get_value();


private:


};

class Total_discount : public Discount {
public:
Total_discount (string type , int value , int min);
Total_discount(bool none);
string get_type();
int get_min_discount();
int  get_value();

private:
int min;


};



#endif