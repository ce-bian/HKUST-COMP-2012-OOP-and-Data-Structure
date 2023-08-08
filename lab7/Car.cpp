#include <iostream>
#include "Car.h"
using namespace std;

Car:: Car(int nc,Color color, int mileage):engine(nc){

	this->color=color;
	this->mileage=mileage;
}

Car::~Car(){
	 cout<<"Calling Car's destructor on the following car:"<<endl;
	 print();
}

Color Car:: getColor() const{
	return color;
}

int Car:: getMileage() const{
	return mileage;
}

int Car:: getEngine() const{
	return engine.getNumCylinder();
}

void Car:: start(){
	cout<<"Car with "<<engine.getNumCylinder()<<"-cylinder engine started."<<endl;
}

void Car::brake(int distance){
	cout<<"Car with "<<engine.getNumCylinder()<<"-cylinder engine stopped."<<endl;
	mileage+=distance;
	cout<<"Driving distance: "<<distance<<endl;
}

void Car::print() const{
	cout<<"Engine: "<<engine.getNumCylinder()<<"  "<<"Color: ";
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

