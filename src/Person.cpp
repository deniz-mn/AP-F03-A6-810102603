#include "Person.hpp"

// Person :: Person(){
// 	username = "";
// 	password = "";
// 	is_login = false;
// 	have_account = false;
// }
Person :: Person(const string& username_ , const string& password_){
	username = username_;
	password = password_;
	is_login = true;
	have_account = true;
	
}
Person :: ~Person(){}


bool Person :: login (string username_ , string password_){
	if(username == username_){
		if(password == password_){
			is_login = true;
			return true;
		}
	}
	return false;
}

void Person :: save_login(){  is_login = true; }
string Person :: get_username(){ return username; }
string Person :: get_password(){ return password; }


