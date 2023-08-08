#include "Hashing.h"

typedef struct QuadraticElem{
	int value;
};

class QuadraticProbing:public Hashing{
public:
	QuadraticProbing(int size);
	~QuadraticProbing();

	virtual void reset(int newSize);
	virtual void print();
	virtual bool insert(int newValue);
	virtual int getIndexByhashing(int keyValue);
	bool clearData();

private:
	QuadraticElem* data;

};
