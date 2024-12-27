#include "Restaurant.hpp"

Restaurant :: Restaurant(const string& name_,const string& district_,const vector<shared_ptr<Food>>& menu_,int openning_time_ ,int closing_time_,int num_of_tables_){
	name = name_;
	district = district_;
	menu = menu_;
	closing_time = closing_time_;
	openning_time = openning_time_;
	num_of_tables = num_of_tables_;
	sort(menu.begin(),menu.end(),compare_name);
}

bool  Restaurant :: is_here(string name_){
	if(district == name_)
		return true;
	return false;
}
bool  Restaurant ::  is_same_restaurant(shared_ptr<Restaurant>& restaurant){
	return (name == restaurant->name);
}
void  Restaurant ::   print_name_district(){
	cout<<name<<" ("<<district<<")"<<endl;
}
bool  Restaurant ::   have_food(string name){
	for(auto food : menu){
		if(food->is_this_food(name))
			return true;
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void  Restaurant  ::  print_menu(){
	for(int i=0 ; i<menu.size()-1 ; i++){
			cout<<menu[i]->get_name_food()<<"("<<menu[i]->get_price_food()<<")"<<", ";
	}
	cout<<menu[ menu.size()-1 ]->get_name_food()<<"("<<menu[ menu.size()-1 ]->get_price_food()<<")"<<endl;
}
void  Restaurant  ::  print_detail(){
	cout<<"Name: "<<name<<endl;
	cout<<"District: "<<district<<endl;
	cout<<"Time: "<<openning_time<<"-"<<closing_time<<endl;
	cout<<"Menu: ";
	print_menu();
	//cout<<

}

int Restaurant :: get_openning (){ return openning_time; }
string Restaurant :: get_name_restaurant(){ return name ;}

bool compare_name(shared_ptr<Food>& a ,shared_ptr<Food>& b){
	return a->get_name_food()[0] < b->get_name_food()[0];
}
