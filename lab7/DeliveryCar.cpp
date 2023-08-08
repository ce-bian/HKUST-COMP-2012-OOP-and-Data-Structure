#include <iostream>
#include "DeliveryCar.h"
using namespace std;

DeliveryCar::DeliveryCar(int nc, Color color, int mileage,int charge):Vehicle(nc,color,mileage){
	chargePerMile=charge;
}

DeliveryCar::~DeliveryCar(){
	cout<<"Calling Vehicle's destructor on the following car:"<<endl;
	print();
   cout<<endl;
}

void DeliveryCar::setChargePerMile(int charge){
	chargePerMile=charge;
}

int DeliveryCar::getCharge(){
	return chargePerMile;
}

void DeliveryCar::start(){
Vehicle::start();
}


void DeliveryCar::brake(int distance){
	Vehicle::brake(distance);
		}

void DeliveryCar::print() const{
	cout<<"Information of the delivery car:"<<endl;
	Vehicle::print();
	cout<<"DeliveryCar's charge per mile:"<<chargePerMile<<endl;
	cout<<"DeliveryCar's calculated charge:"<<chargePerMile*Vehicle::getMileage()<<endl;

		}
