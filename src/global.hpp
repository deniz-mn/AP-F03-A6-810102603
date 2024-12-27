#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include<fstream>
#include <memory>
#include <algorithm>

using namespace std;

const string POST = "POST";
const string PUT = "PUT";
const string GET = "GET";
const string DELETE = "DELETE";



const string EMPTY = "Empty";
const string NOT_FOUND = "Not Found";
const string BAD_REQUEST = "Bad Request";
const string PERMISSION_DENIED = "Permission Denied";

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
#endif