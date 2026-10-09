#include "Neighborhood.hpp"
Neighborhood :: Neighborhood (string name_,vector<string> neighbors_){
	name = name_;
	neighbors = neighbors_;
}
void   Neighborhood :: print (){
	cout<<name<<": ";
	print_vector_with_seprator(neighbors , ',');
}
bool   Neighborhood :: is_equal(string name_){
	if(name_ == name)
		return true;

	return false;
}


string Neighborhood :: get_name_district(){ return name; }
vector<string>  Neighborhood ::  get_neighbors(){ return neighbors; }


//////////////////////////////////////////////////////////////////////

void print_vector_with_seprator(vector<string> neighbors, char separator) {
    for (size_t i = 0; i < neighbors.size(); ++i) {
        if (i) cout << separator << " ";
        cout << neighbors[i];
    }
    cout << endl;
}
