#ifndef PERSON_HPP
#define PERSON_HPP

#include "global.hpp"
#include "Exception.hpp"
#include "Neighborhood.hpp"
//#include "Reservation"

class Person{
public:
	//Person();
	Person(const string& username_ ,const string& password_);
	~Person();
	bool is_equal(string username_ , string password_);
	bool is_login(string username_ , string password_);
	bool get_login();
	void save_login();

	void save_district(shared_ptr<Neighborhood> n);
	
	void logout();
	string get_username();
	string get_password();
	shared_ptr<Neighborhood> get_district();
private:
	string username;
	string password;
	//vector<Reservation*> reservations;
	shared_ptr<Neighborhood> district ;
	bool login;
	bool have_account;
};

#endif
