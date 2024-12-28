#include "CmdHandler.hpp"
#include "Person.hpp"
#include "global.hpp"
#include "Utaste.hpp"
#include "Exception.hpp"

//int argc,char *argv[]
int main(int argc,char *argv[]){
	
	string line;
	auto  utaste = make_shared<Utaste>();
	CmdHandler cmd(utaste);
	
	utaste->save_restaurant_input(argv[1]);
	utaste->save_neighbors_input(argv[2]);
	// utaste->print();
	
	


	while(getline(cin,line)){
		cmd.check_cmd(line);
	}
	
	

}