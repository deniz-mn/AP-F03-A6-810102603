#include "CmdHandler.hpp"
#include "person.hpp"
#include "global.hpp"
#include "utaste.hpp"

int main(){

	string input;
	CmdHandler cmdd;
	getline(cin,input);
	cmdd(input);
	cmdd.check_cmd();


}