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

	if(cmd[0] == POST){

	}
	if(cmd[0] == PUT){
		
	}
	if(cmd[0] == GET){
		
	}
	if(cmd[0] == DELETE){
		
	}
	else{
		cout<<BAD_REQUEST<<endl;
	}
}

