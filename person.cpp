#include "person.hpp"

person :: person(){
	username = "";
	password = "";
	vector<reservation> reservations = {};
	is_login = flase;
	have_account = flase;
}
void person :: signup (string username_ , string password_){
	username = username_ ;
	password = password_ ;
	is_login = true;
	have_account = true;
}
void person :: save_login(){  is_login = true; }
string person :: get_username(){ return username; }
string person :: get_password(){ return password; }