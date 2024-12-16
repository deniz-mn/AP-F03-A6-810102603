#include "CmdHandler.hpp"


CmdHandler :: CmdHandler(shared_ptr<Utaste> utaste) : utaste(utaste){
	
}
CmdHandler :: ~CmdHandler(){

}
vector<string>  CmdHandler :: add_to_vector (string s){
	vector<string> cmd;
	istringstream ss (s);
	string word;
	while(ss>>word)
		cmd.push_back(word);

	return cmd;
}
void CmdHandler :: check_cmd (string s){

	vector<string> cmd = add_to_vector(s);

	
	if(cmd[0] == "login"){
		utaste->login(cmd[1] , cmd[2]);
	}
	if(cmd[0] == "signup"){
		utaste->signup(cmd[1] , cmd[2]);
	}
	if(cmd[0] == "print"){
		utaste->print();
	}
}

