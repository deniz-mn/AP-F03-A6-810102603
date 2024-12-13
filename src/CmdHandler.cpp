#include "CmdHandler.hpp"

CmdHandler :: CmdHandler{
	vector<string> c = {};
	cmd = c;
}
CmdHandler :: CmdHandler(string input){
	stringstream ss (input);
	stirng word;
	while(ss>>word)
		cmd.push_back(word);
}
CmdHandler :: ~CmdHandler{}
void CmdHandler :: check_cmd (){

	if(cmd[0] == "login"){
		utaste.login(cmd[1] , cmd[2]);
	}
	if(cmd[0] == "signup"){
		utaste.signup(cmd[1] , cmd[2]);
	}

}

