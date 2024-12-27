#include "CmdHandler.hpp"


CmdHandler :: CmdHandler(shared_ptr<Utaste> utaste) : utaste(utaste){
	user_login = false;
}
CmdHandler :: ~CmdHandler(){

}
vector<string> add_to_vector (string s);

bool  CmdHandler ::  is_login(){
	return user_login;
}
void   CmdHandler :: login(){
	user_login =  true;
}
void   CmdHandler :: logout(){
	user_login  = false;
}


void CmdHandler :: check_cmd (string s){

	vector<string> cmd = add_to_vector(s);

try{

		if(cmd[CMD_TYPE] == POST){
			
			if(cmd[1] == "signup"){
				utaste->signup(cmd[CMD_USERNAME],cmd[CMD_PASSWORD]);
				login();
			}
			if(cmd[1] == "login"){
				utaste->login(cmd[CMD_USERNAME],cmd[CMD_PASSWORD]);
				login();
			}
			if(cmd[1] == "logout"){
				utaste->logout();
				logout();
			}

			
		

		}


		else if(cmd[CMD_TYPE] == PUT){
			if(!is_login())
				throw Premission_Denied();

			if(cmd[1] == "my_district")
				utaste->save_person_district(cmd[CMD_DISTRICT_NAME] );
		


		}

		else if(cmd[CMD_TYPE] == GET){
			if(!is_login())
				throw Premission_Denied();

			if(cmd[1] == "districts"){
				if(cmd.size() == CMD_FULL_ARGS)
					utaste->show_special_districts(cmd[ CMD_FULL_ARGS-1 ]);
				if(cmd.size() == CMD_MINIMAL_ARGS)
					utaste->show_districts();
			}
			if(cmd[1] == "restaurants"){
				if(cmd.size() == CMD_FULL_ARGS)
					utaste->show_special_restaurants(cmd[ CMD_FULL_ARGS-1 ]);
				if(cmd.size() == CMD_MINIMAL_ARGS)
					utaste->show_all_restaurants();

			}
			if(cmd[1] == "restaurant_detail"){
				utaste->get_restaurant_detail(cmd[ CMD_RESTAURANT_NAME ]);
			}


		
		}


		else if(cmd[CMD_TYPE] == DELETE){
			if(!is_login())
				throw Premission_Denied();

		
		}
		else{
			
			throw Bad_Request();
		}

		
}

catch(Exception& ex){
	
	cout<<ex.show_error()<<endl;
		
}


}

vector<string>	add_to_vector (string s){
	vector<string> cmd;
	istringstream ss (s);
	bool inQuotes = false;
	string word , name;

	while (ss >> word){

	 if (inQuotes){
	 	name += " " + word;
	 	if (!word.empty() && word.back() == '"'){
	 	 inQuotes = false; cmd.push_back(name);
	 	}
	 }
	 else { 
	 	if (!word.empty() && word.front() == '"'){
	 		 inQuotes = true; name = word;
	 		 if (word.back() == '"'){
	 		 	 inQuotes = false; cmd.push_back(name);
	 		 	} 
	 		 }
	 	else { cmd.push_back(word); } }
	 
    }
	return cmd;
}
