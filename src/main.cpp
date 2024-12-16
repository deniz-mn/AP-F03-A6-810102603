#include "CmdHandler.hpp"
#include "Person.hpp"
#include "global.hpp"
#include "Utaste.hpp"

int main(){

	
	auto  utaste = make_shared<Utaste>();
	CmdHandler cmdd(utaste);
	string input;
	
	while(true){
		
		getline(cin,input);
		cout<<"befor checking cmd"<<endl;
		cmdd.check_cmd(input);
		cout<<" first cycle of while cmd"<<endl;
	}
	
	

}