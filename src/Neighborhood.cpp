#include "Neighborhood.hpp"
Neighborhood :: Neighborhood (string name_,vector<string> neighbors_){
	name = name_;
	neighbors = neighbors_;
}
void Neighborhood :: print (){
	cout<<name<<endl;
	for(auto n : neighbors){
		cout<<n<<" yeki az hamsaye hasttt"<<endl;
	}
}