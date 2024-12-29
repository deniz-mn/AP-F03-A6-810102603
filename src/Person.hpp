#ifndef PERSON_HPP
#define PERSON_HPP

#include "global.hpp"
#include "Exception.hpp"
#include "Neighborhood.hpp"
#include "Reservation.hpp"

class Person{
public:
	//Person();
	Person(const string& username_ ,const string& password_);
	~Person();

	bool is_equal(string username_ , string password_);
	bool is_login(string username_ , string password_);
	bool get_login();
	void save_login();
	void logout();

	void save_district(shared_ptr<Neighborhood> n);

	bool has_reservation_at(int time);
	void save_person_reservation(shared_ptr<Reservation>& r);
	bool has_reservation_id(string restaurant_name ,int id);

	
	
	string get_username();
	string get_password();
	shared_ptr<Neighborhood> get_district();
private:
	string username;
	string password;
	vector<shared_ptr<Reservation>> reservations;
	shared_ptr<Neighborhood> district ;
	bool login;
	bool have_account;
};
bool compare_time(shared_ptr<Reservation>& a , shared_ptr<Reservation>& b);
#endif
