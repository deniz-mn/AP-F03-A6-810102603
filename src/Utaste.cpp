
#include "Utaste.hpp"

Utaste :: Utaste(){
	}
Utaste :: ~Utaste(){
	
}

vector<string> file_reader (string file_name);
vector<string> string_seprator(string line , char seprator);
vector<shared_ptr<Food>> save_menu (string input);
string remove_double_quote(string word);


void Utaste :: save_restaurant_input(const string& file_name){
	
	vector<string> file_input = file_reader(file_name);

	for(int i=0 ; i<file_input.size() ; i++){
		auto restaurant_data = string_seprator(file_input[i] , ',');
		auto foods = save_menu(restaurant_data[2]);
		auto restaurant = make_shared<Restaurant>(restaurant_data[0],restaurant_data[1],foods, stoi(restaurant_data[3]),stoi(restaurant_data[4]),stoi(restaurant_data[5]));
		restaurants.push_back(restaurant);
	}
}


void Utaste :: save_neighbors_input(const string& file_name){

	vector<string> file_input = file_reader(file_name);

	for(int i=0 ; i<file_input.size() ; i++){
		auto neighborhood_data = string_seprator(file_input[i] , ',');
		auto neighbors = string_seprator(neighborhood_data[1],';');
		auto neighborhood = make_shared<Neighborhood>(neighborhood_data[0],neighbors);
		neighborhoods.push_back(neighborhood);
	}
}
bool check_login(string username,string password){}
bool wrong_pass(string username, string password){}
bool find_username(string username){}


void Utaste :: signup(string& username_ , string& password_){

	string username = remove_double_quote(username_);
	string password = remove_double_quote(password_);
	if(check_login(username,password))
		throw	Premission_Denied();
	
	if(find_person(username))
		throw	Bad_Request();
	
	else{
		auto p = make_shared<Person>(username , password);
		persons.push_back(p);
	}	
}
void Utaste :: login(string& username_ , string& password_){

	string username = remove_double_quote(username_);
	string password = remove_double_quote(password_);

	if(check_login(username,password))
		throw	Premission_Denied();
	if(!find_username(username))
		throw	Not_Found();
	if(wrong_pass(username,password))
		throw	Premission_Denied();
	else{
		auto p = find_person(username);
		p->save_login();
	}	
}

bool Utaste :: check_login(string username,string password){
	auto p = find_person(username);
		if(p->get_login())
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
shared_ptr<Person> Utaste :: find_person(string username){
	for(auto p : persons){
		if(p->get_username() == username)
			return p;
	}
}
bool  Utaste ::  wrong_pass(string username, string password){
	
	auto p = find_person(username);
	if(p->get_password() == password)
		return false;
	return true;
}


vector<string> file_reader (string file_name){
		
		ifstream file(file_name);
		string line;
		vector<string> file_input;
		
		while(getline(file,line))
			file_input.push_back(line);
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
string remove_double_quote(string word){

	return word.substr(1,word.length()-2);
}




