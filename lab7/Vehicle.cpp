#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle:: Vehicle(int nc,Color color, int mileage):Engine(nc){
	this->color=color;
	this->mileage=mileage;
}

Vehicle::~Vehicle(){
	 cout<<"Calling Vehicle's destructor on the following car:"<<endl;
	 print();
	 cout<<endl;
}

Color Vehicle:: getColor() const{
	return color;
}

int Vehicle:: getMileage() const{
	return mileage;
}

int Vehicle:: getEngine() const{
	return Engine::getNumCylinder();
}

void Vehicle:: start(){
	cout<<"Vehicle with "<<Engine::getNumCylinder()<<"-cylinder engine started."<<endl;
}

void Vehicle::brake(int distance){
	cout<<"Vehicle with "<<Engine::getNumCylinder()<<"-cylinder engine stopped."<<endl;
	mileage+=distance;
	cout<<"Driving distance: "<<distance<<endl;
}

void Vehicle::print() const{
	cout<<"Engine: "<<Engine::getNumCylinder()<<"  "<<"Color: ";
	switch(color){
	case Black:cout<<"Black"; break;
	case Grey:cout<<"Grey"; break;
	case White:cout<<"White"; break;
	case Silver:cout<<"Silver"; break;
	case Red:cout<<"Red"; break;
	case Blue:cout<<"Blue"; break;
	}
	cout<<"  "<<"Current Mileage: "<<mileage<<endl;

}
