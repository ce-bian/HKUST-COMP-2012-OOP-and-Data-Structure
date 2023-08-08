#include "Vehicle.h"
class DeliveryCar: protected Vehicle{
	friend class Vehicle;
  public:
	  DeliveryCar(int nc, Color color, int mileage,int charge);
	  ~DeliveryCar();
	  void setChargePerMile(int charge);
	  int getCharge();
	  void start();
	  void brake(int distance);
	  void print() const;

  private:
	  int chargePerMile;
};
