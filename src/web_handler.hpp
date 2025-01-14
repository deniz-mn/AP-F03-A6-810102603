#ifndef WEB_HANDLER_HPP
#define WEB_HANDLER_HPP



#include "CmdHandler.hpp"
#include "../server/server.hpp"
#include "Utaste.hpp"

using namespace std;

// class RequestHandler{
// public:
// 	virtual Response* callback(Request* req) =0;
// 	virtual ~RequestHandler(){}
// };
class home_handler : public RequestHandler {
public:
	home_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};


class signup_handler : public RequestHandler {
public:
	signup_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};

class login_handler : public RequestHandler { 
public:
	login_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};

class logout_handler : public RequestHandler {
public:
	logout_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};

class view_all_restaurants_handler : public RequestHandler {
public:
	view_all_restaurants_handler(shared_ptr<Utaste> utaste, CmdHandler*cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};
class view_restaurant_handler : public RequestHandler  {
public:
	view_restaurant_handler (shared_ptr<Utaste> utaste, CmdHandler*cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};


class view_reserves_handler : public RequestHandler {
public:
	view_reserves_handler (shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};

class bad_request_handler : public RequestHandler {
public:
	Response* callback(Request* req);
};

class not_found_handler : public RequestHandler  {
public:
	Response* callback(Request* req);
};

class permission_denied_handler : public RequestHandler {
public:
	Response* callback(Request* req);
};


#endif