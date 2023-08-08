#include "Hashing.h"

typedef struct DoubleElem{
	int value;
};

class DoubleHashing:public Hashing{
public:
	DoubleHashing(int size);
	~DoubleHashing();

	virtual void reset(int newSize);
	virtual void print();
	virtual bool insert(int newValue);
	virtual int getIndexByhashing(int keyValue);
	bool clearData();

private:
	DoubleElem *data;

};
