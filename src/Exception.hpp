#ifndef EXCEPTION.HPP
#define EXCEPTION.HPP

#include "global.hpp"

class Exception{

public:
	Exception(string message_);
	~Exception();
	string show_error();

private:
	string message;
};

class Empty : public Exception{
public:
	Empty();
	~Empty();
};

class Not_Found : public Exception{
public:
	Not_Found();
	~Not_Found();
};

class Bad_Request: public Exception{
public:
	Bad_Request();
	~Bad_Request();
};

class Premission_Denied: public Exception{
public:
	Premission_Denied();
	~Premission_Denied();
};

#endif