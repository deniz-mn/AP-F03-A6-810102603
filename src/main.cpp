#include "CmdHandler.hpp"
#include "Person.hpp"
#include "global.hpp"
#include "Utaste.hpp"

int main(){

	
	Utaste* utaste;

	for(int i=0 ; i<2 ; i++){
		cout<<"i = "<<i<<endl;
		string input;
		getline(cin,input);
		CmdHandler cmdd(input ,utaste);
		cout<<"befor checking cmd"<<endl;
		cmdd.check_cmd();
		cout<<" first cycle of while cmd"<<endl;

	}
	// while(getline(cin,input)){
	// 	CmdHandler cmdd(input ,&utaste);
	// 	cout<<"befor checking cmd"<<endl;
	// 	cmdd.check_cmd();
	// 	cout<<" first cycle of while cmd"<<endl;
	// }
	
	

}