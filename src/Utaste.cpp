
#include "Utaste.hpp"

Utaste :: Utaste(){
	cout<<"utaste constractor called"<<endl;
}
Utaste :: ~Utaste(){
	cout<<"utaste distractor called"<<endl;
	for(auto p : persons){
		delete p;
	}
	persons.clear();
	cout<<"utaste dinstractor finished"<<endl;
}

void Utaste :: login(string username , string password){
	for(auto p : persons){
		if(p->login(username,password)){
			cout<<"peyda shod"<<endl;
		}
	}
	cout<<"nabodd"<<endl;
}
void Utaste :: signup (string& username , string& password){
	cout<<"vared signup shod"<<endl;
	Person* p = new Person(username , password);
	cout<<"hee new shod"<<endl;
	
		persons.push_back(p);
		cout<<"signup anjam shoddd"<<endl;
}
void Utaste :: print(){
	for(auto p : persons){
		cout<<p->get_username()<<"esmame"<<endl;
		cout<<p->get_password()<<"passwordame"<<endl;
	}
}