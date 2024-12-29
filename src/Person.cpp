#include "Person.hpp"

Person :: Person(const string& username_ , const string& password_){
	username = username_;
	password = password_;
	login = true;
	have_account = true;
	
}
Person :: ~Person(){}
bool   Person :: is_equal(string username_ , string password_){
	if(username == username_  && password == password_)
		return true;
	return false;
}
bool   Person :: is_login (string username_ , string password_){
	if(username == username_){
		return login;
	}
	return false;
}
void   Person :: save_login(){ login = true; }
bool   Person :: get_login(){ return login; }
void   Person :: logout(){ login = false; }
//////////////////////////////////////////////////////////////////////////////////////////////////////
string Person :: get_username(){ return username; }
string Person :: get_password(){ return password; }
shared_ptr<Neighborhood> Person :: get_district(){ return district; }

void   Person :: save_district(shared_ptr<Neighborhood> n){
	district = n;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool   Person :: has_reservation_at(int time){
	for(auto r : reservations){
		if(r->is_at_time(time))
			return true;
	}
	return false;
}
bool   Person ::  has_reservation_id(string restaurant_name ,int id){
	for(auto r : reservations){
		if(r->is_equal(id) && (r->get_name_restaurant() == restaurant_name ))
			return true;
	}
}
void   Person :: save_person_reservation(shared_ptr<Reservation>& r){
	reservations.push_back(r);
	sort(reservations.begin() , reservations.end(),compare_time);
}
bool compare_time(shared_ptr<Reservation>& a , shared_ptr<Reservation>& b){
	return a->get_start() < b->get_start();
}


