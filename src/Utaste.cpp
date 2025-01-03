
#include "Utaste.hpp"

Utaste :: Utaste(){
	}
Utaste :: ~Utaste(){
	
}

vector<string> file_reader (string file_name);
vector<string> string_seprator(string line , char seprator);
vector<shared_ptr<Food>> save_menu (string input);



void Utaste :: save_restaurant_input(const string& file_name){
	
	vector<string> file_input = file_reader(file_name);

	for(int i=0 ; i<file_input.size() ; i++){
		auto restaurant_data = string_seprator(file_input[i] , ',');
		auto foods = save_menu(restaurant_data[2]);
		auto restaurant = make_shared<Restaurant>(restaurant_data[0],restaurant_data[1],foods, stoi(restaurant_data[3]),stoi(restaurant_data[4]),stoi(restaurant_data[5]));
		restaurants.push_back(restaurant);
	}
	sort(restaurants.begin() , restaurants.end() , compare_first_char_restaurant);
}


void Utaste :: save_neighbors_input(const string& file_name){

	vector<string> file_input = file_reader(file_name);
	
	for(int i=0 ; i<file_input.size() ; i++){
		auto neighborhood_data = string_seprator(file_input[i] , ',');
		auto neighbors = string_seprator(neighborhood_data[1],';');
		sort(neighbors.begin() , neighbors.end() , compare_first_char);
		auto neighborhood = make_shared<Neighborhood>(neighborhood_data[0],neighbors);
		neighborhoods.push_back(neighborhood);
	}
}
void Utaste :: save_discount_input(const string& file_name){

	vector<string> file_input = file_reader(file_name);

	for(int i=0 ; i<file_input.size() ; i++){
		auto line = string_seprator(file_input[i] , ',');
		auto restaurant = find_restaurant_by_name(line[0]);
		auto total_discount = string_seprator(line[1] , ';');
		auto first_order_discount = string_seprator(line[2] , ';');
		auto item_discount = string_seprator(line[3] , '|');
		restaurant->save_discounts(total_discount,first_order_discount,item_discount);
	}


}




///////////////////////////////////////////////////////////////////////////////////////////////



bool check_login(string username,string password){}
bool wrong_pass(string username, string password){}
bool find_username(string username){}


void Utaste :: signup(string& username , string& password){
	
	if(find_username(username)){
		throw	Bad_Request();
	}
	else if(check_login(username,password) )
		throw	Premission_Denied();
	else if( get_login_person() != nullptr )
		throw	Premission_Denied();
	
	else{
		auto p = make_shared<Person>(username , password);
		persons.push_back(p);
	}	

	
}
void Utaste :: login(string& username , string& password){

	if(!find_username(username))
		throw	Not_Found();
	else if(wrong_pass(username,password))
		throw	Premission_Denied();
	else if(check_login(username,password) || get_login_person() != nullptr )
		throw	Premission_Denied();
	else{
		auto p = find_person(username,password);
		p->save_login();
	}	
	
}
void Utaste :: logout(){
	int n = 0;
	for(auto p : persons){ 
		if(p->get_login()){
			p->logout();
			n++;
		}
	}
	if(n == 0)
		throw	Premission_Denied();

		
}
bool Utaste :: check_login(string username,string password){
	
	auto p = find_person(username,password);
	if(p == nullptr){
		return false;
	}
	else if(p->get_login())
		return true;
		
	return false;
}
bool Utaste :: find_username(string username){
	for(auto p : persons){
		if(p->get_username() == username)
			return true;
	}
	return false;
}
shared_ptr<Person> Utaste :: find_person(string username, string password){
	
	for(auto p : persons){
		if(p->is_equal(username,password))
			return p;
	}
	return nullptr;
}
bool  Utaste ::  wrong_pass(string username, string password){
	for(auto p : persons){
		if(p->get_username() == username){
			if(!p->is_equal(username,password))
				return true;
		}
	}
	return false;
}


/////////////////////////////////////////////////////////////////////////////////////////////////

void  Utaste :: show_special_districts(string name){
	bool found = false;

	if( neighborhoods.size() == 0)
		throw 	Empty();

	for(auto n : neighborhoods){
		if(n->is_equal(name)){
			n->print();
			found = true;
		}
	}
	if(!found)
		throw Not_Found();
}
void  Utaste :: show_districts(){

	if( neighborhoods.size() == 0)
		throw 	Empty();

	for(auto n : neighborhoods){
			n->print();
	}
}
shared_ptr<Person>  Utaste :: get_login_person(){

	for(auto p : persons){ 
		if(p->get_login()){
			return p;
		}
	}
	return nullptr;
}

/////////////////////////////////////////////////////////////////////////////////////////////


shared_ptr<Neighborhood>  Utaste :: get_district_by_name(string name){
	bool found = false;
	for(auto n : neighborhoods){
		if(n->is_equal(name)){
			found = true;
			return n;
		}
	}
	if(!found)
		throw Not_Found();
}
void  Utaste ::  save_person_district(string name){
	auto p = get_login_person();
	auto n = get_district_by_name(name);
	p->save_district(n);
}


//////////////////////////////////////////////////////////////////////////////////////////////
shared_ptr<Neighborhood>  Utaste ::  get_district (string name){
	for(auto n : neighborhoods){
		if(n->is_equal(name))
			return n;
	}
}
bool  Utaste :: contain_restaurant(vector<shared_ptr<Restaurant>>& restaurant_list , shared_ptr<Restaurant>& restaurant){
	for(auto& r : restaurant_list){
		if(r ->is_same_restaurant(restaurant))
			return true;
	}
	return false;
}

void  Utaste :: save_restaurants_in_district(string name, vector<shared_ptr<Restaurant>>& closest_restaurants){
	
	for(auto r : restaurants){
		if( r->is_here(name) && !contain_restaurant(closest_restaurants, r) ){
			closest_restaurants.push_back(r);
		}
	}
}
void Utaste :: save_closest_restaurants( shared_ptr<Neighborhood> district, vector<shared_ptr<Restaurant>>& closest_restaurants){
  queue<string> neighborhoods_queue;
  map<string, bool> has_added_to_queue;

  has_added_to_queue[district->get_name_district()] = true;
  neighborhoods_queue.push(district->get_name_district());

  while (!neighborhoods_queue.empty()){
    string neighborhood = neighborhoods_queue.front();
    neighborhoods_queue.pop();
    save_restaurants_in_district(neighborhood, closest_restaurants);
    shared_ptr<Neighborhood> neighborhood_district = get_district(neighborhood);
    	for (auto n : neighborhood_district->get_neighbors()){
      	if (!has_added_to_queue.count(n)){
        		has_added_to_queue[n] = true;
        		neighborhoods_queue.push(n);
          	}
      	}
  	}
}
void  Utaste :: save_sort_restaurants(vector<shared_ptr<Restaurant>>& closest_restaurants){
	auto p = get_login_person();
	auto district = p->get_district();

	if(district == nullptr)
		throw Not_Found();
	if(restaurants.size() == 0)
		throw Empty();
	
	save_closest_restaurants(district , closest_restaurants);
}
void  Utaste :: show_all_restaurants(){
	vector<shared_ptr<Restaurant>> closest_restaurants;
	save_sort_restaurants(closest_restaurants);
	for(auto r : closest_restaurants){
		r->print_name_district();
	}
}
void  Utaste :: show_special_restaurants(string food){
	vector<shared_ptr<Restaurant>> closest_restaurants;
	save_sort_restaurants(closest_restaurants);
	for(auto r : closest_restaurants){
		if(r->have_food(food))
			r->print_name_district();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////

void   Utaste :: get_restaurant_detail( string restaurant_name){

	bool found = false;
	
	for(auto r : restaurants){
		if(r->get_name_restaurant() ==restaurant_name){
			found = true;
			r->print_detail();

		}
	}
	if(found == false)
		throw Not_Found();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
shared_ptr<Restaurant>  Utaste ::  find_restaurant_by_name(string& name){
	bool found = false;
	
	for(auto r : restaurants){
		if(r->get_name_restaurant() == name){
			found = true;
			return r;
		}
	}
	if(found == false)
		throw Not_Found();
}
void   Utaste :: add_reservation(string restaurant_name , int table_id , int start_time , int end_time , string foods){
	
	auto r = find_restaurant_by_name(restaurant_name);
	
	auto p = get_login_person();

	auto ordered_food = string_seprator(foods , ',');


	if( !(r->is_during_operating_hours(start_time)) || !(r->is_during_operating_hours(end_time)) || start_time<1 || end_time >24 )
		throw  Premission_Denied();

	if( (p->has_reservation_at(start_time , end_time))){
		throw  Premission_Denied();
	}
	auto reservation = r->check_reservation_in_restaurant(table_id , start_time , end_time ,ordered_food);

	p->save_person_reservation(reservation);

	reservation->print_reservation_req();
	
}
///////////////////////////////////////////////////////////////////////////////////////////////
int    Utaste ::   num_of_reservation_ut(){
	
	int total = 0 ;
	auto p = get_login_person();
	total = p->num_of_reservation();
	return total;
}

void   Utaste ::   show_special_reservation(string restaurant_name , int id){
	
		if( num_of_reservation_ut() == 0)
			throw Empty();
		
		else{

		auto p = get_login_person();
		
		if(!p->has_reservation_id(restaurant_name, id)){
			 throw Premission_Denied();
		}
			   

		auto r = find_restaurant_by_name(restaurant_name);
		r->print_reservation_id(id);
		}

}
void   Utaste ::   show_all_reservation(){
	if( num_of_reservation_ut() == 0){
			throw Empty();
	}
			

	for(auto r : restaurants){
		r->print_all_reservation();
	}
}
void   Utaste ::   show_res_reservation(string restaurant_name ){
	if( num_of_reservation_ut() == 0)
				throw Empty();

		auto r = find_restaurant_by_name(restaurant_name);
		r->print_all_reservation();
}
void   Utaste ::  delete_reservation(string restaurant_name , int id){

	auto p = get_login_person();
	p->person_delete_reservation(restaurant_name , id);
	auto r = find_restaurant_by_name(restaurant_name);
	r->restaurant_delete_reseravtion(id);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void   Utaste ::   increase_budget(int amount){
	if(amount < 0)
		throw Bad_Request();

	auto p = get_login_person();
	p->update_person_budget(amount , '+');
}
void   Utaste ::   show_budget(){
	auto p = get_login_person();
	p->show_person_budget();

}
///////////////////////////////////////////////////////////////////////////////////////////////
vector<string> file_reader (string file_name){
		
		ifstream file(file_name);
		string line;
		vector<string> file_input;
		
		while(getline(file,line)){
			file_input.push_back(line);
		}

		
	return file_input;
}
vector<string> string_seprator(string line , char seprator){
	vector<string> seprated_string;
	string str;

		for(int i=0 ; i<line.length() ; i++){
			if(line[i] != seprator){
				str += line[i];
			}
			if(line[i] == seprator || i == line.length()-1 ){
				seprated_string.push_back(str);
				str.clear();
			}
		}
		return seprated_string;
}
vector<shared_ptr<Food>> save_menu (string input){

	vector<string> menu = string_seprator(input , ';');
	vector<shared_ptr<Food>> foods;
		for(int j=0 ; j<menu.size() ; j++){
			vector<string> menu_item = string_seprator(menu[j], ':');
			auto food = make_shared<Food>(menu_item[0],stoi(menu_item[1]));
			foods.push_back(food);
		}
		return foods;
}

bool compare_first_char_restaurant(shared_ptr<Restaurant>& a ,shared_ptr<Restaurant>& b){
	return a->get_name_restaurant()[0] < b->get_name_restaurant()[0];
}

bool compare_first_char(string& a , string& b){
	return a[0] < b[0];
}



