#include "CmdHandler.hpp"

// CmdHandler :: CmdHandler(){
// 	vector<string> c = {};
// 	cmd = c;
// }
CmdHandler :: CmdHandler(string s , Utaste* utaste) : utaste(utaste){
	stringstream ss (s);
	string word;
	while(ss>>word)
		cmd.push_back(word);
}
CmdHandler :: ~CmdHandler(){

	delete utaste;
	cout<<"pak kardamesh cmd handler rooo"<<endl;
}

void CmdHandler :: check_cmd (){

cout<<"check cmd shoro shod"<<endl;
	if(cmd[0] == "login"){
		utaste->login(cmd[1] , cmd[2]);
	}
	if(cmd[0] == "signup"){
		utaste->signup(cmd[1] , cmd[2]);
	}
	if(cmd[0] == "print"){
		utaste->print();
	}

	cout<<"check cmd tamom shod"<<endl;

}

