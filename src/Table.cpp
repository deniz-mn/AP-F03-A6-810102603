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
}
