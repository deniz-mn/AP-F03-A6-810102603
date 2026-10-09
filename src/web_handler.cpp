#include "CmdHandler.hpp"
#include "web_handler.hpp"
#include <cstdlib>
#include <iostream>
#include "Exception.hpp"
#include <ctime>
#include <random>
#include <iomanip>

namespace {
string active_session;
string new_session() {
    random_device random;
    ostringstream token;
    for (int i = 0; i < 8; ++i) token << hex << setw(8) << setfill('0') << random();
    active_session = token.str();
    return active_session;
}
bool authenticated(Request* req, CmdHandler* handler) {
    return handler->is_login() && !active_session.empty() && req->getSessionId() == active_session;
}
int integer_param(const string& value) {
    try {
        size_t used = 0;
        int result = stoi(value, &used);
        if (used != value.size()) throw Bad_Request();
        return result;
    } catch (const std::exception&) { throw Bad_Request(); }
}
Response* error_response(Exception& error) {
    const string message = error.show_error();
    if (message == BAD_REQUEST) return Response::redirect("/badRequest");
    if (message == NOT_FOUND) return Response::redirect("/notFound");
    if (message == EMPTY) return Response::redirect("/empty");
    return Response::redirect("/permissionDenied");
}
string escape_html(const string& value) {
    string result;
    for (char c : value) {
        switch (c) {
            case '&': result += "&amp;"; break;
            case '<': result += "&lt;"; break;
            case '>': result += "&gt;"; break;
            case '"': result += "&quot;"; break;
            case '\'': result += "&#39;"; break;
            default: result += c;
        }
    }
    return result;
}
}


home_handler::home_handler(shared_ptr<Utaste> utaste , CmdHandler* cmd_handler)
	: utaste(utaste) , cmd_handler(cmd_handler) {}


Response* home_handler::callback(Request* req) {
    Response* res = new Response();
    res->setHeader("Content-Type", "text/html");
    std::string body = R"(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Home</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f9f9f9;
                color: #333;
                text-align: center;
            }
            .nav {
                margin: 20px 0;
            }
            .nav a {
                margin: 0 10px;
                text-decoration: none;
                color: #007BFF;
                font-size: 18px;
            }
            .nav a:hover {
                text-decoration: underline;
            }
        </style>
    </head>
    <body>
        <h1>Welcome to UTaste</h1>
        <div class="nav">
            <a href="/signup">signup</a>
            <a href="/logout">Logout</a>
            <a href="/login">Login</a>
            <a href="/addReservation">addReservation</a>
            <a href="/viewReservations">View Reservations</a>
            <a href="/viewAllRestaurants">View Restaurants</a>
        </div>
    </body>
    </html>
    )";
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
	res->setSessionId(new_session());
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
res->setSessionId(new_session());
return res;
}


logout_handler :: logout_handler(shared_ptr<Utaste> utaste , CmdHandler*cmd_handler)
	: utaste(utaste) , cmd_handler(cmd_handler) {}

Response* logout_handler::callback(Request* req) {
    if (!authenticated(req, cmd_handler)) return Response::redirect("/permissionDenied");
    try { utaste->logout(); cmd_handler->logout(); }
    catch (Exception& ex) { return error_response(ex); }
    active_session.clear();
    auto res = Response::redirect("/Home");
    res->setHeader("Set-Cookie", "sessionId=; Max-Age=0; Path=/; HttpOnly; SameSite=Lax");
    return res;
}


view_all_restaurants_handler :: view_all_restaurants_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler)
 		: utaste(utaste) , cmd_handler(cmd_handler) {}

Response* view_all_restaurants_handler::callback(Request* req) {
    // if (!authenticated(req, cmd_handler)) {
    //     return Response::redirect("/permissionDenied");
    // }

    Response* res = new Response();
    res->setHeader("Content-Type", "text/html");

    std::string body = R"(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>All Restaurants</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f9f9f9;
                color: #333;
                text-align: center;
            }
            ul {
                list-style-type: none;
                padding: 0;
            }
            li {
                margin: 10px 0;
            }
            a {
                text-decoration: none;
                color: #007BFF;
                font-size: 18px;
            }
            a:hover {
                text-decoration: underline;
            }
            .button {
                display: inline-block;
                padding: 10px 20px;
                margin-top: 20px;
                font-size: 16px;
                color: white;
                background-color: #007BFF;
                border: none;
                border-radius: 5px;
                cursor: pointer;
                text-decoration: none;
            }
            .button:hover {
                background-color: #0056b3;
            }
        </style>
    </head>
    <body>
        <h1>All Restaurants</h1>
        <ul>
    )";

    auto restaurants = utaste->get_all_restaurants();
    for (const auto& restaurant : restaurants) {
        body += "<li><a href=\"/viewRestaurant?name=" + utils::urlEncode(restaurant->get_name_restaurant()) + "\">";
        body += escape_html(restaurant->get_name_restaurant()) + "</a></li>";
    }

    body += R"(
        </ul>
        <a href="/Home" class="button">Back to Home</a>
    </body>
    </html>
    )";

    res->setBody(body);
    return res;
}


view_restaurant_handler :: view_restaurant_handler(shared_ptr<Utaste> utaste, CmdHandler* cmd_handler)
 		: utaste(utaste) , cmd_handler(cmd_handler) {}

Response* view_restaurant_handler::callback(Request* req) {
    if (!authenticated(req, cmd_handler)) {
        return Response::redirect("/permissionDenied");
    }

    // if (!req->getQueryParam("name").empty()) {
    //     return Response::redirect("/badRequest");
    // }

    std::string restaurant_name = req->getQueryParam("name");
    Response* res = new Response();
    res->setHeader("Content-Type", "text/html");

    std::ostringstream body;
    body << R"(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Restaurant Details</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f9f9f9;
                color: #333;
                text-align: center;
                padding: 20px;
            }
            .details {
                margin: 20px auto;
                padding: 20px;
                border: 1px solid #ddd;
                border-radius: 8px;
                background: #fff;
                max-width: 600px;
                box-shadow: 0 4px 8px rgba(0,0,0,0.1);
            }
            a {
                text-decoration: none;
                color: #007BFF;
            }
            a:hover {
                text-decoration: underline;
            }
        </style>
    </head>
    <body>
        <h1>Restaurant Details</h1>
        <div class="details">
    )";

    try {
        std::ostringstream details;
       
        utaste->get_restaurant_detail(restaurant_name, details);
        body << details.str();
    } catch (Exception& ex) {
        delete res;
        return error_response(ex);
    }
    body << R"(
        </div>
        <a href="/viewAllRestaurants">Back to All Restaurants</a>
    </body>
    </html>
    )";

    res->setBody(body.str());
    return res;
}
Response* bad_request_handler::callback(Request* req) {
	Response* res = new Response(Response::Status::badRequest);
	res->setHeader("Content-Type", "text/html");
	res->setBody("<html><body><h1>400 Bad Request</h1><p>Your request could not be processed.</p></body></html>");
return res;
}
Response* empty_handler::callback(Request* req) {
    Response* res = new Response();
    res->setHeader("Content-Type", "text/html");
    res->setBody("<html><body><h1>No Reservations</h1><p>No matching reservations were found.</p></body></html>");
return res;
}

Response* not_found_handler::callback(Request* req) {
	Response* res = new Response(Response::Status::notFound);
	res->setHeader("Content-Type", "text/html");
	res->setBody("<html><body><h1>404 Not Found</h1><p>The page you requested could not be found.</p></body></html>");
return res;
}

Response* permission_denied_handler::callback(Request* req) {
	Response* res = new Response(Response::Status::forbidden);
	res->setHeader("Content-Type", "text/html");
	res->setBody("<html><body><h1>403 Forbidden</h1><p>You do not have permission to access this page.</p></body></html>");
return res;
}





add_reservation_handler :: add_reservation_handler(std::shared_ptr<Utaste> utaste, CmdHandler* cmd_handler)
            : utaste(utaste), cmd_handler(cmd_handler) {}

Response* add_reservation_handler::callback(Request* req) {
    if (!authenticated(req, cmd_handler)) return Response::redirect("/permissionDenied");
    try {
        utaste->add_reservation(req->getBodyParam("restaurant_name"),
            integer_param(req->getBodyParam("table_id")), integer_param(req->getBodyParam("start_time")),
            integer_param(req->getBodyParam("end_time")), req->getBodyParam("foods"));
        return Response::redirect("/viewReservations");
    } catch (Exception& ex) { return error_response(ex); }
}








view_reserves_handler  :: view_reserves_handler (shared_ptr<Utaste> utaste, CmdHandler* cmd_handler)
        : utaste(utaste) , cmd_handler(cmd_handler) {}
        
Response* view_reserves_handler :: callback(Request* req){
	if (!authenticated(req, cmd_handler)) {
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
body << "div { margin-bottom: 20px; padding: 10px; border: 1px solid #ccc; border-radius: 5px; background: #fff; }";
body << "</style>";
body << "</head>";
body << "<body>";
body << "<h1>All Reservations</h1>";

try{ 
    if (!req->getQueryParam("reserve_id").empty() && req->getQueryParam("restaurant_name").empty()) throw Bad_Request();
    if (!req->getQueryParam("restaurant_name").empty() && !req->getQueryParam("reserve_id").empty()) {

            std::string restaurant_name = req->getQueryParam("restaurant_name");
            int reserve_id = integer_param(req->getQueryParam("reserve_id"));
            ostringstream output;
                utaste->show_special_reservation(restaurant_name, reserve_id,output);
            body << "<div>" << output.str() << "</div>";
    } 
    else if (!req->getQueryParam("restaurant_name").empty()) {

            std::string restaurant_name = req->getQueryParam("restaurant_name");
            body << "<div><strong>Reservations for " << escape_html(restaurant_name) << ":</strong><br>";
            ostringstream output;
            utaste->show_res_reservation(restaurant_name,output);
            body <<output.str();
            body << "</div>";
    }
    else {

        body << "<div><strong>All Reservations:</strong><br>";
        ostringstream output;

         utaste->show_all_reservation(output);

        body <<output.str();
        body << "</div>";

    }
}
catch (Exception& ex){
        delete res;
        if(ex.show_error() == "Bad Request"){
            return Response::redirect("/badRequest");
            }
        else if(ex.show_error() == "Not Found"){
            return Response::redirect("/notFound");
        }
        else if(ex.show_error() == "Empty"){
            return Response::redirect("/empty");
        }
        else{
            return Response::redirect("/permissionDenied");
            }
        }

    body << "<a href=\"/Home\">Back to Home</a>";
    body << "<a href=\"/logout\">Logout</a>";
    body << "</body>";
    body << "</html>";
	
	res->setBody(body.str());
	return res;
}

