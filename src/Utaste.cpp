
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


// void Utaste :: login(string username , string password){
// 	for(auto p : persons){
// 		if(p->login(username,password)){
			
// 		}
// 	}
// }
void Utaste :: signup(string& username , string& password){

	auto p = make_shared<Person>(username , password);
		persons.push_back(p);
		
}
void Utaste :: print(){
	for(auto n : neighborhoods){
		n->print();
	}
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

