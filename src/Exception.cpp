#include "Exception.hpp"

Exception :: Exception(string message_){
	message = message_;
}
Exception :: ~Exception(){}

string	Exception :: show_error(){
	return message;
}

Empty :: Empty() : Exception(EMPTY){}
Empty :: ~Empty(){}

Bad_Request :: Bad_Request () : Exception(BAD_REQUEST){}
Bad_Request :: ~Bad_Request (){}


Not_Found :: Not_Found () : Exception(NOT_FOUND){}
Not_Found :: ~Not_Found (){}


Premission_Denied :: Premission_Denied() : Exception(PERMISSION_DENIED){} 
Premission_Denied :: ~Premission_Denied(){}
Ok  :: Ok () : Exception(OK){}
Ok  :: ~Ok () {}


