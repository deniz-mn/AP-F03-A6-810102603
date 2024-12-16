#ifndef CMDHANDLER_HPP
#define CMDHANDLER_HPP

#include "global.hpp"
#include "Utaste.hpp"



class CmdHandler{

public:
	//CmdHandler();
	CmdHandler(shared_ptr<Utaste> utaste);
	~CmdHandler();
	void  check_cmd (string s);
	vector<string>  add_to_vector (string s);
	

private:
	
	shared_ptr<Utaste>  utaste;
};

#endif