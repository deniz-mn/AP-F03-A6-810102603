#ifndef TABLE_HPP
#define TABLE_HPP

#include "global.hpp"
#include "Reservation.hpp"

class Table{

public:
	Table(int num);
	bool has_reservation_at(int time);
	void save_table_reservation( shared_ptr<Reservation>& r);
private:
	int id;
	vector <shared_ptr<Reservation>> reservations;
};

#endif