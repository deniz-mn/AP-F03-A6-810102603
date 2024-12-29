#include "Restaurant.hpp"

Restaurant :: Restaurant(const string& name_,const string& district_,const vector<shared_ptr<Food>>& menu_,int openning_time_ ,int closing_time_,int num_of_tables_){
	name = name_;
	district = district_;
	menu = menu_;
	closing_time = closing_time_;
	openning_time = openning_time_;
	num_of_tables = num_of_tables_;
	reservation_id = 0;
	sort(menu.begin(),menu.end(),compare_name);

	for(int i = 0 ; i<num_of_tables-1 ; i++){
		auto t = make_shared<Table>(i+1);
		tables.push_back(t);

	}
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
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool  Restaurant  :: is_during_operating_hours(int time){
	return time>openning_time && time<closing_time;
}
shared_ptr<Food>  Restaurant  :: find_food_by_name(string name){
	bool found = false;
	for(auto f : menu){
		if(f->is_this_food(name))
			found = true;
			cout<<" qqaza peyda shode "<<f->get_price_food()<<" qeimat"<<endl;
			return f;
	}
	if(!found)
		throw Not_Found();
}
vector<shared_ptr<Food>>  Restaurant  :: save_food_in_vector(vector<string>& foods){
	vector<shared_ptr<Food>> f;
	for(auto food : foods){
		cout<<food<<" esem qazaa"<<endl;
		f.push_back( find_food_by_name(food) );
		cout<<" yeki push shodd"<<endl;

	}
	cout<<" save_food_in_vector  tamamm shodd"<<endl;
	return f;
}

shared_ptr<Reservation>  Restaurant  :: check_reservation_in_restaurant(int table_id ,int  start_time ,int  end_time ,vector<string> foods) {
	//cout<<name<<" esme resturaneee"<<tables.size()<<" number of tables"<<endl;
	if( table_id > tables.size() || table_id<1)
		throw  Not_Found();
	table_id --;
	auto t = tables[ table_id ];
	table_id ++;
	//cout<<" find table "<<table_id<<endl;

	if( (t->has_reservation_at(start_time)) || (t->has_reservation_at(end_time) )){
		cout<<" table reservation dareee nemitonii"<<endl;
		throw  Premission_Denied();	
	}
	
	reservation_id ++;
	//cout<<reservation_id <<" id reservation in bodd"<<endl;
	auto  ordered_food =  save_food_in_vector(foods);
	//cout<<" save kard food haro toye pointer"<<endl;

	auto r = make_shared<Reservation>(name  ,start_time , end_time , ordered_food ,reservation_id,table_id);
	//cout<<" reservation sakhte shod"<<endl;
	t->save_table_reservation(r);
	return r;
}
	
////////////////////////////////////////////////////////////
int    Restaurant :: num_of_reservation(){
	int total = 0 ;
	for(auto t : tables){
		total += t->num_of_reservation_table();
	}
	return total;
}
void   Restaurant :: print_reservation_id(int id){
	if(num_of_reservation() == 0)
		throw  Empty();

	bool found = false;
	for(auto t : tables){
		found = true;
		t->print_reservation_id(id);
	}
	if(!found)
		throw Not_Found();
}
void   Restaurant :: print_all_reservation(){
	if(num_of_reservation() == 0)
		throw  Empty();

	for(auto t : tables){
		t->print_reservation();
	}
	
}
shared_ptr<Reservation>  Restaurant ::  find_reservation_id(int id){
	for(auto t : tables){
		if( t->table_has_reserve_id(id)){
			return t->get_reservation_by_id(id);
		}
	}
}
void   Restaurant :: restaurant_delete_reseravtion(int id){
	auto to_delete = find_reservation_id(id);
	to_delete.reset();
}
/////////////////////////////////////////////////////////
int Restaurant :: get_openning (){ return openning_time; }
string Restaurant :: get_name_restaurant(){ return name ;}

bool compare_name(shared_ptr<Food>& a ,shared_ptr<Food>& b){
	return a->get_name_food()[0] < b->get_name_food()[0];
}
