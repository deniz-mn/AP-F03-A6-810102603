#include "utaste.hpp"


utaste :: utaste(){
	vector <person> p = {};
	people = p ;

}

void utaste :: login (string username , string password){
	for(int i=0 ; i<people.size() ; i++){
		if(people[i].get_username() == username){
			if(people[i].get_password() == password)
				people[i].save_login();
		}
	}
	cout<<"login anjam shod"<<endl;
}
void utaste :: signup (string username , string password){
	person p ;
	p.signup(username ,password);
	people.push_back(p);
	cout<<"sign anjam shod"<<endl;
}
void utaste :: print (){
	for(auto p : people){
		cout<<p.get_username<<"esmame"<<endl;
		cout<<p.get_password<<"passwordame"<<endl;
	}
}
