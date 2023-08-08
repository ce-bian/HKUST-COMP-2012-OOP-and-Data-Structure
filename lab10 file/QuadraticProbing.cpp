#include <iostream>
#include "QuadraticProbing.h"
using namespace std;

QuadraticProbing::QuadraticProbing(int size):Hashing(size),data(NULL){
	reset(size);
}

QuadraticProbing::~QuadraticProbing(){
	clearData();
}

void QuadraticProbing::reset(int newSize){
	if(data!=NULL)
		clearData();
	data = new QuadraticElem[newSize];
	for(int i=0;i<newSize;i++){
		data[i].value=EMPTY;
	}
	bucketSize=newSize;
}

void QuadraticProbing::print(){
	cout<<"[";
    for(int i=0;i<bucketSize-1;i++){
    	if(data[i].value==EMPTY){
    		cout<<"_,";
    	}
    	else
    		cout<<data[i].value<<",";
    }
    if(data[bucketSize-1].value==EMPTY)
    	cout<<"_";
    else{
    	cout<<data[bucketSize-1].value;
    }
	cout<<"]"<<endl;
}

int QuadraticProbing::getIndexByhashing(int newValue){
	int key=newValue%bucketSize;
		if(data[key].value==EMPTY){
			return key;
		}
		   for(int i=1;;i++){
		    	int j=key+i*i;
		    	if(data[j%bucketSize].value==EMPTY){

		    		return j%bucketSize;
		    	}
		    }

		return -1;
}

bool QuadraticProbing::insert(int newValue){
	int key=newValue%bucketSize;
	if(data[key].value==EMPTY){
		data[key].value=newValue;
		return true;
	}
    for(int i=1;;i++){
    	int j=key+i*i;
    	if(data[j%bucketSize].value==EMPTY){
    		data[j%bucketSize].value=newValue;
    		return true;
    	}
    }



	return false;

}

bool QuadraticProbing::clearData(){
	if(bucketSize!=0){
		delete[] data;
		return true;
	}
	else
		return false;
}

