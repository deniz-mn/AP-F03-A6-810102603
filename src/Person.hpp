#ifndef PERSON_HPP
#define PERSON_HPP

#include "global.hpp"
#include "Exception.hpp"
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
	string get_username();
	string get_password();
private:
	string username;
	string password;
	//vector<Reservation*> reservations;
	bool login;
	bool have_account;
};

#endif
