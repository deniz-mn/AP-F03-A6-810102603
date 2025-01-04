#ifndef DISCOUNT_HPP
#define DISCOUNT_HPP

#include "global.hpp"



class Discount {
public:
Discount(string type , int value);
Discount(bool none);

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

private:
string food;


};

class First_order_discount : public Discount {
public:
First_order_discount(string type , int value);
First_order_discount(bool none);


private:


};

class Total_discount : public Discount {
public:
Total_discount (string type , int value , int min);
Total_discount(bool none);

private:
int min;


};



#endif