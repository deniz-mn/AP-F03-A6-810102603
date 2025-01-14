#ifndef TABLE_HPP
#define TABLE_HPP

#include "global.hpp"
#include "Reservation.hpp"
#include "Exception.hpp"

class Table{

public:
	Table(int num);
	bool has_reservation_at(int start_time , int end_time);
	bool is_this_id(int id_);
	void save_table_reservation( shared_ptr<Reservation>& r);
	void print_reservation_id(int id,ostream& out);
	void print_reservation();
	int num_of_reservation_table();
	bool table_has_reserve_id(int id);
	shared_ptr<Reservation>  get_reservation_by_id(int id);
	void delete_reservation_table(int id);
	shared_ptr<Reservation>  find_reservation_by_id(int id);
	void print_reservation_hours(ostream& out);
	int get_final_reservation_price(int id);
	void print_table_details ();
private:
	int id;
	vector <shared_ptr<Reservation>> reservations;
};

#endif