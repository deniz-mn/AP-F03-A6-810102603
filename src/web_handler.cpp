#include "CmdHandler.hpp"
#include "web_handler.hpp"
#include <cstdlib>
#include <iostream>
#include "ex.hpp"
#include <ctime>


home_handler::home_handler(shared_ptr<Utaste> utaste , CmdHandler* cmd_handler)
	: utaste(utaste) , cmd_handler(cmd_handler) {}


Response* home_handler :: callback(Request* req) {
	if (!cmd_handler->is_login()) {
		return Response :: redirect("/permissionDenied");
	}
	Response* res = new Response();
	res->setHeader("Content-Type", "text/html");
string username = utaste->get_login_person()->get_username();
string body;
body += "<!DOCTYPE html>";
body += "<html lang=\"en\">";
body += "<head>";
body += " <meta charset=\"UTF-8\">";
body += " <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
body += " <title>UTaste</title>";
body += "<style>";
body += " body {font-family: 'Arial', sans-serif;background-color: #f4f4f4;margin:0;padding: 20px;color: #333;}";
body += " h1 {color: #81daf8;}img {border-radius: 50%;margin: 20px 0;}";
body += " p {font-size: 18px;}";
body += " a {display: inline-block;margin: 10px;padding: 10px 20px;background-color:#81daf8;color: white;text-decoration: none;border-radius: 5px;transition: background-color 0.3s ease;}";body += " a:hover {background-color: #6ccbe5;}";
body += " .logout-btn {padding: 10px 20px;color: white;background-color:#f54f4f;border-radius: 5px;}";
body += " header {background-color: #333;padding: 10px 0;text-align: center;color:white;}";
body += " .footer {background-color: #333;padding: 10px 0;text-align: center;color:white;position: fixed;width: 100%;bottom: 0;}";
body += "</style>";
body += "</head>";
body += "<body style=\"text-align: center;\">";
body += "<header><h1>Welcome to UTaste</h1></header>";
body += " <p>Name: " + username + "</p>";
body += " <a href=\"/logout\" class=\"logout-btn\">Logout</a>";
body += "<div class=\"footer\">&copy; 2025 UTaste Inc.</div>";
body += "</body>";
body += "</html>";
res->setBody(body);
return res;
}


signup_handler :: signup_handler(shared_ptr<Utaste> utaste , CmdHandler*cmd_handler)
	: utaste(utaste) , cmd_handler(cmd_handler) {}

Response* signup_handler :: callback(Request* req) {
string username = req->getBodyParam("username");
string password = req->getBodyParam("password");
try{
	utaste->signup(username,password);
	cmd_handler->login();
}
catch (Exception& ex){
	if(ex.show_error() == "Bad Request"){
		return Response::redirect("/badRequest");
	}
	else if(ex.show_error() == "Not Found"){

	return Response::redirect("/notFound");
	}
	else{
	return Response::redirect("/permissionDenied");
	}
}

	Response* res = Response::redirect("/Home");
	res->setSessionId(username);
	return res;
}

login_handler :: login_handler(shared_ptr<Utaste> utaste , CmdHandler* cmd_handler)
		: utaste(utaste) , cmd_handler(cmd_handler) {}

Response* login_handler :: callback(Request* req) {
	string username = req->getBodyParam("username");
	string password = req->getBodyParam("password");
try{
	utaste->login(username,password);
	cmd_handler->login();
  }
catch (Exception& ex){
	if(ex.show_error() == "Bad Request"){
	return Response::redirect("/badRequest");
	}
	else if(ex.show_error() == "Not Found"){
	return Response::redirect("/notFound");
	}
	else{
	return Response::redirect("/permissionDenied");
	}
	}
Response* res = Response::redirect("/Home");
res->setSessionId(username);
return res;
}


logout_handler :: logout_handler(shared_ptr<Utaste> utaste , CmdHandler*cmd_handler)
	: utaste(utaste) , cmd_handler(cmd_handler) {}

Response* logout_handler :: callback(Request* req) {
	try{
	utaste->logout();cmd_handler->logout();
	}
	catch (Exception& ex){
		if(ex.show_error() == "Bad Request"){
			return Response::redirect("/badRequest");
		}
		else if(ex.show_error() == "Not Found"){
				return Response::redirect("/notFound");
		}
		else{
			return Response::redirect("/permissionDenied");
		}
	}	
	return Response::redirect("/Home");
}


view_all_restaurants_handler :: view_all_restaurants_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler)
 		: utaste(utaste) , cmd_handler(cmd_handler) {}

Response* view_all_restaurants_handler :: callback(Request* req){
	if (!cmd_handler->is_login()) {
		return Response :: redirect("/permissionDenied");
	}
	Response* res = new Response();
	res->setHeader("Content-Type", "text/html");

string body;
body += "<!DOCTYPE html>";
body += "<html lang=\"en\">";
body += "<head>";
body += " <meta charset=\"UTF-8\">";
body += " <meta name=\"viewport\" content=\"width=device-width, initial-
scale=1.0\">";
body += " <title>All Restaurants</title>";
body += " <style>";
body += " body {font-family: 'Arial', sans-serif;background-color: #f4f4f4;margin:
0;padding: 20px;color: #333;}";
body += " h1 {color: #81daf8;}";
body += " p {font-size: 18px;}";
body += " .restaurant {margin: 10px; padding: 10px; border: 1px solid #ccc; border-
radius: 5px; background-color: #fff;}";
body += "</style>";
body += "</head>";
body += "<body style=\"text-align: center;\">";
body += " <h1>All Restaurants</h1>";
vector<shared_ptr<Restaurant>> restaurants = utaste->get_all_restaurants();
for (auto restaurant : restaurants) {
body += "<div class=\"restaurant\">";
body += " <p><strong>" + restaurant->get_name_restaurant() + "</strong></p>";
body += " <a href=\"/viewRestaurant?name=" + restaurant->get_name_restaurant() + "\">View Details</a>";
body += "</div>";
}
body += " <a href=\"/logout\" class=\"logout-btn\">Logout</a>";
body += "</body>";
body += "</html>";
res->setBody(body);
return res;
}

Response* bad_request_handler::callback(Request* req) {
	Response* res = new Response();
	res->setHeader("Content-Type", "text/html");
	res->setBody("<html><body><h1>400 Bad Request</h1><p>Your request could notbe processed.</p></body></html>");
return res;
}

Response* not_found_handler::callback(Request* req) {
	Response* res = new Response();
	res->setHeader("Content-Type", "text/html");
	res->setBody("<html><body><h1>404 Not Found</h1><p>The page you requestedcould not be found.</p></body></html>");
return res;
}

Response* permission_denied_handler::callback(Request* req) {
	Response* res = new Response();
	res->setHeader("Content-Type", "text/html");
	res->setBody("<html><body><h1>403 Forbidden</h1><p>You do not havepermission to access this page.</p></body></html>");
return res;
}


Response* view_reserves_handler :: callback(Request* req){
	if (!cmd_handler->is_login()) {
		return Response::redirect("/permissionDenied");
	}
Response* res = new Response();
res->setHeader("Content-Type", "text/html");
std::ostringstream body;
body << "<!DOCTYPE html>";
body << "<html lang=\"en\">";
body << "<head>";
body << "<meta charset=\"UTF-8\">";
body << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
body << "<title>All Reservations</title>";
body << "<style>";
body << "body { font-family: Arial, sans-serif; background-color: #f4f4f4; margin: 0;padding: 20px; color: #333; }";
body << "h1 { color: #81daf8; }";
body << "p { font-size: 18px; }";
body << "a { color: #007BFF; text-decoration: none; }";
body << "a:hover { text-decoration: underline; }";
body << "div { margin-bottom: 20px; padding: 10px; border: 1px solid #ccc; border-radius: 5px; background: #qf; }";
body << "</style>";
body << "</head>";
body << "<body>";
body << "<h1>All Reservations</h1>";

	if (req->hasQueryParam("restaurant_name") && req->hasQueryParam("reserve_id")) {
			std::string restaurant_name = req->getQueryParam("restaurant_name");
			int reserve_id = std::stoi(req->getQueryParam("reserve_id"));
			body << "<div><strong>Speciﬁc Reservation:</strong><br>";
			body << utaste->show_special_reservation(restaurant_name, reserve_id);
				body << "</div>";
	} 
	else if (req->hasQueryParam("restaurant_name")) {
			std::string restaurant_name = req->getQueryParam("restaurant_name");
			body << "<div><strong>Reservations for " << restaurant_name << ":</strong><br>";
			body << utaste->show_res_reservation(restaurant_name);
			body << "</div>";
	}
	else {
		body << "<div><strong>All Reservations:</strong><br>";
		body << utaste->show_all_reservation();
		body << "</div>";
	}
	body << "<a href=\"/logout\">Logout</a>";
	body << "</body>";
	body << "</html>";
	res->setBody(body.str());
	return res;
}

