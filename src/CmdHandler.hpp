#ifndef CMDHANDLER_HPP
#define CMDHANDLER_HPP

#include "global.hpp"
#include "Utaste.hpp"
#include "Exception.hpp"



class CmdHandler{

public:
	CmdHandler(shared_ptr<Utaste> utaste);
	~CmdHandler();
	void check_cmd (string s);
	bool is_login();
	void login();
	void logout();
	
	
	

private:
	
	shared_ptr<Utaste>  utaste;
	bool user_login;
};


vector<string>  add_to_vector (string s);

#endif