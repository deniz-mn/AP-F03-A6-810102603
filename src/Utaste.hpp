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

	void signup (string& username, string& password);
	void login (string& username , string& password);
	void logout();
	shared_ptr<Person> find_person(string username, string password);
	bool find_username(string username);
	bool check_login(string username,string password);
	bool wrong_pass(string username, string password);

	void show_special_districts(string name);
	void show_districts();
	shared_ptr<Person> get_login_person();

	shared_ptr<Neighborhood>  get_district_by_name(string name);
	void save_person_district(string name);

	bool   contain_restaurant(vector<shared_ptr<Restaurant>>& restaurant_list , shared_ptr<Restaurant>& restaurant);
	shared_ptr<Neighborhood> get_district (string name);
	void   save_closest_restaurants( shared_ptr<Neighborhood> district, vector<shared_ptr<Restaurant>>& closest_restaurants);
	void   save_restaurants_in_district(string name, vector<shared_ptr<Restaurant>>& closest_restaurants);
	void   save_sort_restaurants(vector<shared_ptr<Restaurant>>& closest_restaurants);
	void   show_all_restaurants();
	void   show_special_restaurants(string food);

	void   get_restaurant_detail( string restaurant_name );

	void   add_reservation(string restaurant_name , int table_id , int start_time , int end_time , string foods);
	shared_ptr<Restaurant>  find_restaurant_by_name(string& name);
	void   show_special_reservation(string restaurant_name , int id);
	void   show_all_reservation();
	void   show_res_reservation(string restaurant_name );
	void   delete_reservation(string restaurant_name , int id);



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