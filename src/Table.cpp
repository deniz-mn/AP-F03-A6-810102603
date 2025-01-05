#include "Table.hpp"

Table :: Table(int num){
	id = num ;
}
bool Table ::   is_this_id(int id_){
	if(id == id_)
		return true;
	return false;
}

bool Table ::  has_reservation_at(int start_time , int end_time){
	for( auto r : reservations){
		if(r->is_at_start_time(start_time) || r->is_at_end_time(end_time))
			return true;
	}
	return false;
}
int Table :: num_of_reservation_table(){
	return this->reservations.size();

}
void Table ::  save_table_reservation( shared_ptr<Reservation>& r){

	this->reservations.push_back(r);
	sort(reservations.begin() , reservations.end(),[](const std::shared_ptr<Reservation>& a, const std::shared_ptr<Reservation>& b) { return a->get_time() < b->get_time(); });
}
void Table :: print_reservation_id(int id){
	for(auto r : reservations){
		if(r->is_equal(id)){
			r->print_in_line();
		}
	}
}
shared_ptr<Reservation>  Table ::  find_reservation_by_id(int id){
	for( auto r : reservations){
		if(r->has_reserve_id(id))
			return r;
	}
}
void  Table ::   delete_reservation_table(int id){
	auto to_delete = find_reservation_by_id(id);

	if (to_delete){
			cout<< to_delete->get_reservation_id()<<" id ke mikhad pak kone"<<endl;
			reservations.erase(remove(reservations.begin(), reservations.end(), to_delete), reservations.end());
			to_delete.reset(); 
		} 
	else{ 
		throw Not_Found();
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
void  Table ::  print_reservation_hours(){
	
	cout<<id<<": ";
	if(reservations.size() == 0){
		cout<<endl;
	}
	else {
		for(int i=0 ; i<reservations.size()-1 ; i++){
		cout<<"("<<reservations[i]->get_start()<<"-"<<reservations[i]->get_end()<<"), ";
			}
		cout<<"("<<reservations[ reservations.size()-1 ]->get_start()<<"-"<<reservations[ reservations.size()-1 ]->get_end()<<")"<<endl;
	}
}

