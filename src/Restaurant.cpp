#include "Restaurant.hpp"

Restaurant :: Restaurant(const string& name_,const string& district_,const vector<shared_ptr<Food>>& menu_,int openning_time_ ,int closing_time_,int num_of_tables_){
	if (name_.empty() || openning_time_ < 1 || closing_time_ > 24 || openning_time_ >= closing_time_ || num_of_tables_ < 1)
        throw Bad_Request();
    name = name_;
	district = district_;
	menu = menu_;
	closing_time = closing_time_;
	openning_time = openning_time_;
	num_of_tables = num_of_tables_;
	item_discount = {};
    total_discount = make_shared<Total_discount>(true);
    first_order_discount = make_shared<First_order_discount>(true);
	reservation_id = 0;
	sort(menu.begin(),menu.end(),compare_name);

	for(int i = 0 ; i<num_of_tables ; i++){
		auto t = make_shared<Table>(i+1);
		this->tables.push_back(t);
	}
}
void  Restaurant :: save_discounts(vector<string> total_discount_input,
								   vector<string> first_order_discount_input,
								   vector<string> item_discount_input){

	
    if (first_order_discount_input.size() != 1 && first_order_discount_input.size() != 2) throw Bad_Request();
    if (total_discount_input.size() != 1 && total_discount_input.size() != 3) throw Bad_Request();
	if(first_order_discount_input.size() == 1){
		first_order_discount = make_shared<First_order_discount>(true);
	}
	else if(first_order_discount_input.size() > 1){
		first_order_discount = make_shared<First_order_discount>(first_order_discount_input[0], stoi(first_order_discount_input[1]));
	}
	if(total_discount_input.size() == 1){
		total_discount = make_shared<Total_discount>(true);
	}
	else if(total_discount_input.size() > 2){
		total_discount = make_shared<Total_discount>(total_discount_input[ discount_type ] , stoi(total_discount_input[ discount_value_total ]) ,stoi( total_discount_input[ discount_min ]));
	}
	item_discount.clear();
	if(item_discount_input.empty() || (item_discount_input.size() == 1 && item_discount_input[0] == "none")){
		auto item = make_shared<Item_discount>(true);
		item_discount.push_back(item);
	}
	else {
		for(int i=0 ; i<item_discount_input.size() ; i++){
			auto item_discount_detail = save_item_discount(item_discount_input[i]);
            if (item_discount_detail.size() != 3) throw Bad_Request();
			auto item = make_shared<Item_discount>(item_discount_detail[ discount_type ] , stoi(item_discount_detail[ discount_value_total ]) , item_discount_detail[ discount_food ]);
			item_discount.push_back(item);
		}
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
void Restaurant::print_menu(ostream& out) {
    for (size_t i = 0; i < menu.size(); ++i) {
        if (i) out << ", ";
        out << menu[i]->get_name_food() << "(" << menu[i]->get_price_food() << ")";
    }
    out << "<br>";
}
void  Restaurant  ::  print_total_discount(ostream& out){
	auto total_discount_ptr =  dynamic_pointer_cast<Total_discount>(total_discount);
	if(!total_discount_ptr->is_none()){
		out<<total_discount_ptr->get_type()<<", "
			<<total_discount_ptr->get_min_discount()<<", "
			<<total_discount_ptr->get_value()<<"<br>";
	}
	else{
		out<<"<br>";
	}
	
}
void  Restaurant  ::  print_item_discount(ostream& out){
	vector<shared_ptr<Item_discount>> item_discount_ptr ;
	
	for(auto item : item_discount){
	auto item_ptr = dynamic_pointer_cast<Item_discount>(item);
	if(item_ptr)
		item_discount_ptr.push_back(item_ptr);
	}
	
	if(item_discount_ptr.size() > 0){
		for(int i=0 ; i<item_discount_ptr.size()-1 ; i++){
			if(!item_discount_ptr[i]->is_none()){
				out<<item_discount_ptr[i]->get_name_food()<<"("
					<<item_discount_ptr[i]->get_type()<<": "
					<<item_discount_ptr[i]->get_value()<<"), ";
			}
			
			}
		int last_item = item_discount_ptr.size()-1;
		if(!item_discount_ptr[last_item]->is_none()){
			out<<item_discount_ptr[last_item]->get_name_food()<<"("
				<<item_discount_ptr[last_item]->get_type()<<": "
				<<item_discount_ptr[last_item]->get_value()<<")"<<"<br>";
		}
		else{
			out<<"<br>";
		}	
	}
}
void  Restaurant  ::  print_first_discount(ostream& out){
	auto first_order_discount_ptr = dynamic_pointer_cast<First_order_discount>(first_order_discount);
	if(!first_order_discount_ptr->is_none()){
		out<<first_order_discount_ptr->get_type()<<", "
		   <<first_order_discount_ptr->get_value()<<"<br>";
	}
	else{
		out<<"<br>";
	}
}
void  Restaurant  ::  print_detail(ostream& out){
	out<<"Name: "<<name<<"<br>";
	out<<"District: "<<district<<"<br>";
	out<<"Time: "<<openning_time<<"-"<<closing_time<<"<br>";
	out<<"Menu: ";
	print_menu(out);
	for(auto t : tables){
		t->print_reservation_hours(out);
	}
	
	if(!(total_discount->get_none())){
		out<<"Order Amount Discount: ";
		print_total_discount(out);
	}
	
	if(item_discount.size() > 0){
		out<<"Item Specific Discount: ";
		print_item_discount(out);
	}
	
	if(!(first_order_discount->get_none())){
		out<<"First Order Discount: ";
		print_first_discount(out);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool  Restaurant  :: is_during_operating_hours(int time){
	return time>=openning_time && time<=closing_time;
}
shared_ptr<Food>  Restaurant  :: find_food_by_name(string name){
	bool found = false;
	for(auto f : menu){
		if(f->is_this_food(name)){
			found = true;
			return f;
		}
	}
	if(!found)
		throw Not_Found();
}
vector<shared_ptr<Food>>  Restaurant  :: save_food_in_vector(vector<string>& foods){
	vector<shared_ptr<Food>> f;
	for(auto food : foods){
		f.push_back( find_food_by_name(food) );
	}
	return f;
}

shared_ptr<Reservation> Restaurant::check_reservation_in_restaurant(int table_id, int start_time, int end_time,
        vector<string> foods, bool is_first_order, shared_ptr<Person>& login_person) {
    if (!login_person) throw Premission_Denied();
    if (start_time < 1 || end_time > 24 || start_time >= end_time) throw Bad_Request();
    if (!is_during_operating_hours(start_time) || !is_during_operating_hours(end_time)) throw Premission_Denied();
    if (table_id < 1 || table_id > static_cast<int>(tables.size())) throw Not_Found();
    auto table = tables[table_id - 1];
    if (table->has_reservation_at(start_time, end_time)) throw Premission_Denied();
    auto ordered_food = save_food_in_vector(foods);
    auto reservation = make_shared<Reservation>(name, start_time, end_time, ordered_food,
        reservation_id + 1, table_id, total_discount, first_order_discount, item_discount, is_first_order);
    login_person->update_person_budget(reservation->get_final_price(), '-');
    table->save_table_reservation(reservation);
    ++reservation_id;
    return reservation;
}
	
////////////////////////////////////////////////////////////
int    Restaurant :: num_of_reservation(){
	int total = 0 ;

	for(auto t : tables){
		total += t->num_of_reservation_table();
	}
	return total;
}
void   Restaurant :: print_reservation_id(int id,ostream& out){

	for(auto t : tables){
		t->print_reservation_id(id , out);
	}
	
}
void Restaurant :: print_tables_details(){
	for(auto t : tables){
		cout<<endl;
		t->print_table_details();
		cout<<endl;
	}
}
void   Restaurant :: print_all_reservation(ostream& out){
	
	for(auto t : tables){
		t->print_reservation(out);
	}
}
shared_ptr<Table>  Restaurant ::  find_reservation_table(int id){
	bool found = false;
	for(auto t : tables){
		if( t->table_has_reserve_id(id)){
			found = true;
			return t;
		}
	}

	if(!found)
		throw Not_Found();
}
void   Restaurant :: restaurant_delete_reseravtion(int id , shared_ptr<Person>& login_person){
	auto table = find_reservation_table(id);
	int price = ( table->get_final_reservation_price(id) ) * 0.6;

	login_person->update_person_budget(price , '+');
	table->delete_reservation_table(id);
}
/////////////////////////////////////////////////////////
int Restaurant :: get_openning (){ return openning_time; }
string Restaurant :: get_name_restaurant(){ return name ;}

bool compare_name(shared_ptr<Food>& a ,shared_ptr<Food>& b){
	return a->get_name_food() < b->get_name_food();
}
vector<string> save_item_discount(string line){
	vector<string> save_item;
	string str;
	bool firstPart = true;

	for (char ch : line){
		if(firstPart){
		 	if(ch == ';'){
		 		save_item.push_back(str);
		 		str.clear();
		 		firstPart = false;
		 	}
		 	else{
		 	 str += ch; 
		 	}
		}
		else{
			if(ch == ':' || ch == ';'){
				save_item.push_back(str);
				str.clear();
			}
			else{
				str += ch;
			} 
		} 
	} 
	if(!str.empty()){ 
		save_item.push_back(str); 
	}


		return save_item;
}
