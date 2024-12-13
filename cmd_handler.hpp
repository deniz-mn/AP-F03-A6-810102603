#ifndef CMD_HANDLER_HPP
#define CMD_HANDLER_HPP

#include "global.hpp"
#include "utaste.hpp"



class{

public:
	cmd_handler();
	cmd_handler(string& input);
	~cmd_handler();
	void  check_cmd ();
	

private:
	vector<string> cmd;
}

#endif