#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include<fstream>
#include <memory>
#include <map>
#include <algorithm>
#include <map>
#include <queue>
// #include "APHTTP.h"

using namespace std;

const string POST = "POST";
const string PUT = "PUT";
const string GET = "GET";
const string DELETE = "DELETE";
const string OK = "OK";



const string EMPTY = "Empty";
const string NOT_FOUND = "Not Found";
const string BAD_REQUEST = "Bad Request";
const string PERMISSION_DENIED = "Permission Denied";
const string USERNAME = "username";
const string PASSWORD = "password";
const string RESTAURANT_NAME = "restaurant_name";
const string TABLE_ID = "table_id";
const string START_TIME = "start_time";
const string END_TIME = "end_time";
const string FOODS = "foods";
const string RESERVE_ID = "reserve_id";


const int CMD_TYPE = 0;
const int CMD_USERNAME = 4; 
const int CMD_PASSWORD = 6;
const int CMD_FULL_ARGS = 5; 
const int CMD_MINIMAL_ARGS = 3;
const int CMD_DISTRICT_NAME = 4;
const int CMD_RESTAURANT_NAME = 4;
const int CMD_RESERVE_NAME = 4;
const int CMD_RESERVE_TABLE = 6;
const int CMD_RESERVE_START = 8;
const int CMD_RESERVE_END = 10 ;
const int CMD_RESERVE_FOODS = 12; 
const int CMD_SHOW_RESERVE = 7; 
const int CMD_SHOW_RES_RESERVE = 5; 
const int CMD_ALL_SHOW_RESERVE = 3;

const int discount_type = 0;
const int discount_min = 1;
const int discount_value_total = 2;
const int discount_value_first = 1;
const int discount_food = 1;


#endif
