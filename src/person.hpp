#ifndef PERSON_HPP
#define PERSON_HPP

#include "global.hpp"
#include "reservation.hpp"

class person{

public:
	person();
	void signup(string username_ , string password_);
	void login(string username_ , string password_);
	void save_login();
	string get_username();
	string get_password();

private:
	string username;
	string password;
	vector<reservation> reservations;
	bool is_login;
	bool have_account;
};
#endif