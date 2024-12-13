#ifndef CMDHANDLER_HPP
#define CMDHANDLER_HPP

#include "global.hpp"
#include "utaste.hpp"



class CmdHandler{

public:
	CmdHandler();
	CmdHandler(string input);
	~CmdHandler();
	void  check_cmd ();
	

private:
	vector<string> cmd;
};

#endif