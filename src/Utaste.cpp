
#include "Utaste.hpp"

Utaste :: Utaste(){
	}
Utaste :: ~Utaste(){
	
}

void Utaste :: login(string username , string password){
	for(auto p : persons){
		if(p->login(username,password)){
			
		}
	}
	
}
void Utaste :: signup (string& username , string& password){

	auto p = make_shared<Person>(username , password);
		persons.push_back(p);
		
}
void Utaste :: print(){
	for(auto p : persons){
		cout<<p->get_username()<<"esmame"<<endl;
		cout<<p->get_password()<<"passwordame"<<endl;
	}
}