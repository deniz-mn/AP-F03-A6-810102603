#include "Restaurant.hpp"

Restaurant :: Restaurant(const string& name_,const string& district_,const vector<shared_ptr<Food>>& menu_,int openning_time_ ,int closing_time_,int num_of_tables_){
	name = name_;
	district = district_;
	menu = menu_;
	closing_time = closing_time_;
	openning_time = openning_time_;
	num_of_tables = num_of_tables_;
}
int Restaurant :: get_openning (){ return openning_time; }
string Restaurant :: get_name(){ return name ;}
void Restaurant :: get_menu(){ 
	for(auto f : menu){
		cout<<f->get_name()<<"esme qaza"<<endl;
		cout<<f->get_price()<<"qeimat qaza"<<endl;
	}
}