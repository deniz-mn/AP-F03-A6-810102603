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

int main(int argc,char *argv[]) {

    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " restaurants.csv neighborhoods.csv discounts.csv\n";
        return 1;
    }
	try {
	const int port = 5000; 
	auto utaste = std::make_shared<Utaste>();
	utaste->save_restaurant_input(argv[1]);
	
 	utaste->save_neighbors_input(argv[2]);
 	
 	utaste->save_discount_input(argv[3]);
 	
	CmdHandler cmdHandler(utaste);Server server(port);

	server.get("/", new home_handler(utaste, &cmdHandler));
	server.get("/Home", new home_handler(utaste, &cmdHandler));
	server.get("/signup", new ShowPage("static/signup.html"));
	server.post("/signup", new signup_handler(utaste, &cmdHandler));
	server.get("/login", new ShowPage("static/login.html"));
	server.post("/login", new login_handler(utaste, &cmdHandler));
	server.get("/logout", new logout_handler(utaste, &cmdHandler));
	server.get("/addReservation", new ShowPage("static/addReservation.html"));
	server.post("/addReservation", new add_reservation_handler(utaste, &cmdHandler));
	server.get("/viewAllRestaurants", new view_all_restaurants_handler(utaste, &cmdHandler));
	server.get("/viewRestaurant", new view_restaurant_handler(utaste, &cmdHandler));
	server.get("/viewReservations", new view_reserves_handler(utaste, &cmdHandler));
    server.get("/badRequest", new bad_request_handler());
    server.get("/notFound", new not_found_handler());
    server.get("/permissionDenied", new permission_denied_handler());
    server.get("/empty", new empty_handler());

		cout << "Server is running on port " << port << "..." << std::endl;
		server.run();
	}
	catch (Exception& e) {
        cerr << "Error: " << e.show_error() << endl;
        return 1;
    }
	catch (const std::exception& e) {
		cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
return 0;
}