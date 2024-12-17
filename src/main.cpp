#include "CmdHandler.hpp"
#include "Person.hpp"
#include "global.hpp"
#include "Utaste.hpp"


int main(int argc,char *argv[]){

	
	auto  utaste = make_shared<Utaste>();
	//CmdHandler cmdd(utaste);
	

	utaste->save_restaurant_input(argv[1]);
	utaste->save_neighbors_input(argv[2]);
	utaste->print();
	
	// while(true){
	// 	string input;
	// 	getline(cin,input);
	// 	cmdd.check_cmd(input);
	// }
	
	

}