#include "Hashing.h"

typedef struct LinearElem{
	int value;
};

class LinearProbing:public Hashing{
public:
	LinearProbing(int size);
	~LinearProbing();

	virtual void reset(int newSize);
	virtual void print();
	virtual bool insert(int newValue);
	virtual int getIndexByhashing(int keyValue);

	bool clearData();

private:
	LinearElem* data;
};
