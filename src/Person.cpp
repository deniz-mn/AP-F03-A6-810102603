#include "Person.hpp"

Person :: Person(const string& username_ , const string& password_){
	username = username_;
	password = password_;
	login = true;
	have_account = true;
	
}
Person :: ~Person(){}


bool Person :: is_login (string username_ , string password_){
	if(username == username_){
		if(password == password_){
			login = true;
			return true;
		}
	}
	return false;
}
bool Person :: is_equal(string username_ , string password_){
	if(username == username_  && password == password_)
		return true;
	return false;
}

void Person :: save_login(){ login = true; }
bool Person :: get_login(){ return login; }
string Person :: get_username(){ return username; }
string Person :: get_password(){ return password; }


