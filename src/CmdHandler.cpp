#include "CmdHandler.hpp"


CmdHandler :: CmdHandler(shared_ptr<Utaste> utaste) : utaste(utaste){
	
}
CmdHandler :: ~CmdHandler(){

}
vector<string> add_to_vector (string s);


void CmdHandler :: check_cmd (string s){

	vector<string> cmd = add_to_vector(s);

try{

		if(cmd[0] == POST){

			if(cmd[1] == "signup")
				utaste->signup(cmd[CMD_USERNAME],cmd[CMD_PASSWORD]); 
			if(cmd[1] == "login")
				utaste->login(cmd[CMD_USERNAME],cmd[CMD_PASSWORD]);

			
		

		}


		if(cmd[0] == PUT){
		
		}


		if(cmd[0] == GET){
		
		}


		if(cmd[0] == DELETE){
		
		}
		else{
			throw Bad_Request();
		}
}

catch(Exception& ex){
	cout<<ex.show_error();
		
}


}
vector<string>	add_to_vector (string s){
	vector<string> cmd;
	istringstream ss (s);
	string word;
	while(ss>>word)
		cmd.push_back(word);

	return cmd;
}
