#ifndef PERSON_HPP
#define PERSON_HPP

#include "global.hpp"
#include "food.hpp"
#include "reservation.hpp"

class{

public:

private:
	string username;
	string password;
	vector<reservation> reservations;
	bool login;
	bool have_account;
};
#endif