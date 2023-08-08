#include <iostream>
#include "PoliceCar.h"
using namespace std;

PoliceCar::PoliceCar(int nc,Color c,int m, bool action):Car(nc,c,m){
    inAction=action;
}

PoliceCar::~PoliceCar(){
	cout<<"Calling PoliceCar's destructor on the following police car:"<<endl;
    print();
}

bool PoliceCar::getInAction() const{
	return inAction;
}

void PoliceCar::setInAction(bool action){
	inAction=action;
}

void PoliceCar::print() const{
	cout<<"Information of the police car:"<<endl;
	Car::print();
	cout<<"PoliceCar's state: not in action"<<endl;
   cout<<endl;
}

