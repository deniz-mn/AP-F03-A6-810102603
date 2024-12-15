#ifndef PERSON_HPP
#define PERSON_HPP

#include "global.hpp"
//#include "Reservation"

class Person{
public:
	//Person();
	Person(const string& username_ ,const string& password_);
	~Person();
	void signup (string username_ , string password_);
	bool login (string username_ , string password_);
	void save_login();
	string get_username();
	string get_password();
private:
	string username;
	string password;
	//vector<Reservation*> reservations;
	bool is_login;
	bool have_account;
};

#endif
