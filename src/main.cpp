#include "CmdHandler.hpp"
#include "Person.hpp"
#include "global.hpp"
#include "Utaste.hpp"
#include "Exception.hpp"
#include "Discount.hpp"

#include "../server/server.hpp"
#include "web_handler.hpp"
// int main(int argc,char *argv[]){
	
// 	string line;
// 	auto  utaste = make_shared<Utaste>();
// 	CmdHandler cmd(utaste);
	
// 	utaste->save_restaurant_input(argv[1]);
// 	utaste->save_neighbors_input(argv[2]);
// 	utaste->save_discount_input(argv[3]);

// 	while(getline(cin,line)){
// 		cmd.check_cmd(line);
// 	}
// }

int main() {
	const int port = 8080; 
	auto utaste = std::make_shared<Utaste>();
	CmdHandler cmdHandler(utaste);Server server(port);


	server.get("/Home", new home_handler(utaste, &cmd_handler));
	server.post("/signup", new signup_handler(utaste, &cmdHandler));
	server.post("/login", new login_handler(utaste, &cmdHandler));
	server.get("/logout", new logout_handler(utaste, &cmdHandler));
	server.get("/viewAllRestaurants", new view_all_restaurants_handler(utaste,&cmdHandler));
	server.get("/viewRestaurant", new view_restaurant_handler(utaste, &cmdHandler));
	server.get("/viewReservations", new view_reserves_handler(utaste, &cmdHandler));
	server.setNotFoundErrPage("404.html");

	try {
		cout << "Server is running on port " << port << "..." << std::endl;
		server.run();
	}
	catch (const std::exception& e) {
		cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
return 0;
}