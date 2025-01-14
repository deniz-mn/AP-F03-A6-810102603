#ifndef WEB_HANDLER_HPP
#define WEB_HANDLER_HPP



#include "CmdHandler.hpp"
#include "Request.hpp"
#include "../server/server.hpp"
#include "Utaste.hpp"

using namespace std;

class home_handler {
public:
	home_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};


class signup_handler {
public:
	signup_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};

class login_handler {
public:
	login_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};

class logout_handler {
public:
	logout_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};

class view_all_restaurants_handler {
public:
	view_all_restaurants_handler(shared_ptr<Utaste> utaste, CmdHandler*cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};

class view_reserves_handler {
public:
	view_reserves_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler);
	Response* callback(Request* req);
private:
	shared_ptr<Utaste> utaste;
	CmdHandler* cmd_handler;
};

class bad_request_handler {
public:
	Response* callback(Request* req);
};

class not_found_handler {
public:
	Response* callback(Request* req);
};

class permission_denied_handler {
public:
	Response* callback(Request* req);
};


#endif