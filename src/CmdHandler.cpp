#include "CmdHandler.hpp"


CmdHandler :: CmdHandler(shared_ptr<Utaste> utaste) : utaste(utaste){
  user_login = false;
}
CmdHandler :: ~CmdHandler(){

}

map<string, string> create_cmd_map(vector<string> cmd);

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

  
try{

    vector<string> cmd = add_to_vector(s);
    map<string, string> cmd_map = create_cmd_map(cmd);
    
    if(cmd[CMD_TYPE] == POST){
      
      if(cmd[1] == "signup"){
        if (!cmd_map.count(USERNAME) || !cmd_map.count(PASSWORD))
          throw Bad_Request();
        utaste->signup(cmd_map[USERNAME],cmd_map[PASSWORD]);
        login();
        throw Ok();
      }
      else if(cmd[1] == "login"){
        if (!cmd_map.count(USERNAME) || !cmd_map.count(PASSWORD))
          throw Bad_Request();
        utaste->login(cmd_map[USERNAME],cmd_map[PASSWORD]);
        login();
        throw Ok();
      }
      else if(cmd[1] == "logout"){
        utaste->logout();
        logout();
        throw Ok();
      }
      else if(cmd[1] == "increase_budget"){
        if(!is_login())
          throw Premission_Denied();
        utaste->increase_budget(cmd[4]);
          throw Ok();
      }
      else{
        if(!is_login())
          throw Premission_Denied();
        else if(cmd[1] == "reserve"){
          if (!cmd_map.count(RESTAURANT_NAME) || !cmd_map.count(TABLE_ID) || !cmd_map.count(START_TIME) || !cmd_map.count(END_TIME) || !cmd_map.count(FOODS))
            throw Bad_Request();
          utaste->add_reservation(cmd_map[ RESTAURANT_NAME ] , stoi(cmd_map[TABLE_ID]) , stoi(cmd_map[ START_TIME ]) , stoi(cmd_map[ END_TIME ]), cmd_map[FOODS]);
        }
        else
          throw Bad_Request();
      }
      
    }


    else if(cmd[CMD_TYPE] == PUT){
      if(!is_login())
        throw Premission_Denied();

        else if(cmd[1] == "my_district")
          utaste->save_person_district(cmd[CMD_DISTRICT_NAME] );
      
        else
          throw Bad_Request();
      

    }

    else if(cmd[CMD_TYPE] == GET){
      if(!is_login())
        throw Premission_Denied();

      if(cmd[1] == "districts"){
        if(cmd.size() == CMD_FULL_ARGS)
          utaste->show_special_districts(cmd[ CMD_FULL_ARGS-1 ]);
        else if(cmd.size() == CMD_MINIMAL_ARGS)
          utaste->show_districts();
        else
          throw Bad_Request();
      }

      else if(cmd[1] == "restaurants"){
        if(cmd.size() == CMD_FULL_ARGS)
          utaste->show_special_restaurants(cmd[ CMD_FULL_ARGS-1 ]);
        if(cmd.size() == CMD_MINIMAL_ARGS)
          utaste->show_all_restaurants();

      }

      else if(cmd[1] == "restaurant_detail"){
        utaste->get_restaurant_detail(cmd[ CMD_RESTAURANT_NAME ]);
      }

      else if(cmd[1] == "reserves"){
    
        if(cmd.size() == CMD_SHOW_RESERVE){
          if (!cmd_map.count(RESTAURANT_NAME) || !cmd_map.count(RESERVE_ID))
                throw Bad_Request();
         
          utaste->show_special_reservation(cmd_map[ RESTAURANT_NAME ] , stoi(cmd_map[ RESERVE_ID ]) );
        }
        else if((cmd.size() == CMD_SHOW_RES_RESERVE) && cmd[ CMD_SHOW_RES_RESERVE -2 ] == "restaurant_name")
          utaste->show_res_reservation(cmd[ CMD_SHOW_RES_RESERVE -1 ]);

        else if(cmd.size() == CMD_ALL_SHOW_RESERVE)
          utaste->show_all_reservation();
        
        else
          throw Bad_Request();
      }
      else if(cmd[1] == "show_budget"){
        utaste->show_budget();
      }
      
        
    }


    else if(cmd[CMD_TYPE] == DELETE){
      if(!is_login())
        throw Premission_Denied();

      else if(cmd[1] == "reserve"){

        if (!cmd_map.count(RESTAURANT_NAME) || !cmd_map.count(RESERVE_ID))
          throw Bad_Request();

          utaste->delete_reservation(cmd_map[ RESTAURANT_NAME ] , stoi( cmd_map[ RESERVE_ID ]));
        throw Ok();
      }
      
        
      
    }
    else{
      
      throw Bad_Request();
    }

    
}

catch(Exception& ex){
  
  cout<<ex.show_error()<<endl;
    
}


}

map<string, string> create_cmd_map(vector<string> cmd){
  map<string, string> mp;
  bool flag = 0;
  for (int i = 0; i < cmd.size() - 1; i++){
    if (cmd[i] == "?")
      flag = true;
    else if(flag)
      mp[cmd[i]] = cmd[i + 1];
  }
  return mp;
}

vector<string>  add_to_vector (string s){
  vector<string> cmd;
  istringstream ss (s);
  bool inQuotes = false;
  string word , name;

  while (ss >> word){

   if (inQuotes){
    name += " " + word;
    if (!word.empty() && word.back() == '"'){
      inQuotes = false; 
      name = remove_double_quote(name);
      cmd.push_back(name);
    }
   }
   else { 
    if (!word.empty() && word.front() == '"'){
       inQuotes = true; name = word;
       if (word.back() == '"'){
        inQuotes = false; 
        name = remove_double_quote(name);
         cmd.push_back(name);
        } 
       }
    else { cmd.push_back(word); } }
   
    }
    if(cmd[2] != "?")
      throw Bad_Request();
  return cmd;
}
string remove_double_quote(string word){

  return word.substr(1,word.length()-2);
}
