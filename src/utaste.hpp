#ifndef UTASTE_HPP
#define UTASTE_HPP

#include "global.hpp"
#include "person.hpp"


class utaste{

public:
	utaste();
	void login(string username , string password);
	void signup (string username , string password);

private:
	vector<person> people ;

	
};

#endif