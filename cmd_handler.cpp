#include "cmd_handler.hpp"

cmd_handler :: cmd_handler{
	vector<string> c = {};
	cmd = c;
}
cmd_handler :: cmd_handler(string& input){
	stringstream ss (input);
	stirng word;
	while(ss>>word)
		cmd.push_back(word);
}
cmd_handler :: ~cmd_handler{}
void cmd_handler :: check_cmd (){

	if(cmd[0] == "login"){
		utaste.login(cmd[1] , cmd[2]);
	}
	if(cmd[0] == "signup"){
		utaste.signup(cmd[1] , cmd[2]);
	}

}

