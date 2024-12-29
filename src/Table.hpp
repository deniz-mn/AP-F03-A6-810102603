#ifndef TABLE_HPP
#define TABLE_HPP

#include "global.hpp"
#include "Reservation.hpp"

class Table{

public:
	Table(int num);
	bool has_reservation_at(int time);
	void save_table_reservation( shared_ptr<Reservation>& r);
	void print_reservation_id(int id);
	void print_reservation();
	int num_of_reservation_table();
private:
	int id;
	vector <shared_ptr<Reservation>> reservations;
};
bool compare_time(shared_ptr<Reservation>& a , shared_ptr<Reservation>& b);
#endif