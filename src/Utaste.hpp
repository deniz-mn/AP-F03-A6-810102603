#ifndef UTASTE_HPP
#define UTASTE_HPP

#include "global.hpp"
#include "Person.hpp"
#include "Restaurant.hpp"
#include "Neighborhood.hpp"
#include "Exception.hpp"

class Utaste{

public:
	Utaste();
	~Utaste();
	void save_restaurant_input(const string& file_name);
	void save_neighbors_input(const string& file_name);

	void signup (string& username_ , string& password_);
	void login (string& username_ , string& password_);
	void logout();
	shared_ptr<Person> find_person(string username, string password);
	bool find_username(string username);
	bool check_login(string username,string password);
	bool wrong_pass(string username, string password);

	void show_special_districts(string name_);
	void show_districts();
	shared_ptr<Person> get_login_person();

	shared_ptr<Neighborhood>  get_district_by_name(string name);
	void save_person_district(string name_);

	bool   contain_restaurant(vector<shared_ptr<Restaurant>>& restaurant_list , shared_ptr<Restaurant>& restaurant);
	void   save_restaurants_in_district(string name, vector<shared_ptr<Restaurant>>& closest_restaurants);
	void   save_closest_restaurants( shared_ptr<Neighborhood> district, vector<shared_ptr<Restaurant>>& closest_restaurants);
	void   save_sort_restaurants(vector<shared_ptr<Restaurant>>& closest_restaurants);
	void   show_all_restaurants();
	void   show_special_restaurants(string food_);


	void   get_restaurant_detail( string restaurant_name_ );




	void print();

private:
	vector<shared_ptr<Person>> persons;
	vector<shared_ptr<Restaurant>> restaurants;
	vector<shared_ptr<Neighborhood>> neighborhoods;

};

vector<string> file_reader (string file_name);
vector<string> string_seprator(string line , char seprator);
vector<shared_ptr<Food>> save_menu (string input);
bool compare_first_char_restaurant(shared_ptr<Restaurant>& a ,shared_ptr<Restaurant>& b);
bool compare_first_char(string& a ,string& b);






#endif