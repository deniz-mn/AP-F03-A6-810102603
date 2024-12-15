#ifndef UTASTE_HPP
#define UTASTE_HPP

#include "global.hpp"
#include "Person.hpp"


class Utaste{

public:
	Utaste();
	~Utaste();
	void login(string username , string password);
	void signup (string& username , string& password);
	void print();

private:
	vector<Person*> persons;

};

#endif