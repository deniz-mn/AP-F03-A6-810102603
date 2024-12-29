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
bool   Person :: has_reservation_at(int start_time , int end_time){
	//cout<<" person check konim reserve dare ya na"<<endl;
	if(reservations.size() == 0){
		return false;
	}
		
	for(auto r : reservations){
		//cout<<" check reserve 11111"<<endl;
		//cout<<r->get_start()<<" zamane shoroo"<<endl;
		if(r->is_at_start_time(start_time) || r->is_at_end_time(end_time)){ 
			//cout<<" ham zamani person reserve"<<endl;
			return true;
		}
	//cout<<" Person has_reservation_at falseee"<<endl;
	return false;
	}
}
bool   Person ::  has_reservation_id(string restaurant_name ,int id){
	for(auto r : reservations){
		if(r->is_equal(id) && (r->get_name_restaurant() == restaurant_name ))
			return true;
	}
}
shared_ptr<Reservation>   Person :: find_reservation(string restaurant_name , int id){

	for(auto reserve : reservations){
		if(reserve->is_equal(id) && (reserve->get_name_restaurant() == restaurant_name ))
			return reserve;
	}

}

void   Person ::  person_delete_reservation(string restaurant_name , int id){

	auto to_delete = find_reservation(restaurant_name , id);
	if (to_delete){
			reservations.erase(remove(reservations.begin(), reservations.end(), to_delete), reservations.end());
			to_delete.reset(); 
		} 
	else{ 
		cout << "Reservation not found." << endl;
	}
}
void   Person :: save_person_reservation(shared_ptr<Reservation>& r){
	cout<<" yek reserve save shodd baraye person "<<r->get_start()<<" zamane shoroo"<<endl;
	reservations.push_back(r);
	sort(reservations.begin() , reservations.end(),compare_time);
}
bool compare_time(shared_ptr<Reservation>& a , shared_ptr<Reservation>& b){
	return a->get_start() < b->get_start();
}


