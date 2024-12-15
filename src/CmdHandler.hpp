#ifndef CMDHANDLER_HPP
#define CMDHANDLER_HPP

#include "global.hpp"
#include "Utaste.hpp"



class CmdHandler{

public:
	//CmdHandler();
	CmdHandler(string s,Utaste* utaste);
	~CmdHandler();
	void  check_cmd ();
	

private:
	vector<string> cmd;
	Utaste* utaste;
};

#endif