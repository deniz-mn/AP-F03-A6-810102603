#include "Table.hpp"

Table :: Table(int num){
	id = num ;
}

bool Table ::  has_reservation_at(int time){
	for( auto r : reservations){
		if(r->is_at_time(time))
			return true;
	}
	return false;
}
void Table ::  save_table_reservation( shared_ptr<Reservation>& r){

	reservations.push_back(r);
	sort(reservations.begin() , reservations.end(),[](const std::shared_ptr<Reservation>& a, const std::shared_ptr<Reservation>& b) { return a->get_time() < b->get_time(); });
}
void Table :: print_reservation_id(int id){
	for(auto r : reservations){
		if(r->is_equal(id)){
			r->print_in_line();
		}
	}
}
void Table ::  print_reservation(){
	for(auto r : reservations){
			r->print_in_line();
	}
}
bool Table :: table_has_reserve_id(int id){
	for(auto r : reservations){
		if(r->has_reserve_id(id)){
			return true;
		}
	}
	return false;
}
shared_ptr<Reservation>  Table ::  get_reservation_by_id(int id){
	for(auto r : reservations){
		if(r->has_reserve_id(id)){
			return r;
		}
	}
	return nullptr;
}

int Table :: num_of_reservation_table(){
	return reservations.size();
}