#ifndef VEHICLE_H_
#define VEHICLE_H_
#include "Engine.h"

class Vehicle:private Engine{
	friend class Engine;
public:
	    Vehicle(int nc, Color color, int mileage); // Constructor
		Color getColor() const;
		int getMileage() const;
		int getEngine() const;
		~Vehicle();
		void start();
		void brake(int distance);
		void print() const;
private:

	Color color;
	int mileage;
};

#endif;
