#include <iostream>
#include "DoubleHashing.h"
using namespace std;

DoubleHashing::DoubleHashing(int size):Hashing(size),data(NULL){
	reset(size);
}

DoubleHashing::~DoubleHashing(){
	clearData();
}

void DoubleHashing::reset(int newSize){
	if(data!=NULL)
		 clearData();


		data = new DoubleElem[newSize];
		for(int i=0;i<newSize;i++){
			data[i].value=EMPTY;
		}
		bucketSize=newSize;
}

void DoubleHashing::print(){
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

int DoubleHashing::getIndexByhashing(int newValue){
	int key=newValue%bucketSize;
	if(data[key].value==EMPTY){
		return key;
	}
	for(int i=1;;i++){
		int j=key+i*(5-newValue%5);
		if(data[j%bucketSize].value==EMPTY){
			return j%bucketSize;
		}
	}
	return -1;


}

bool DoubleHashing::insert(int newValue){
	int key=newValue%bucketSize;
	if(data[key].value==EMPTY){
		data[key].value=newValue;
		return true;
	}
	for(int i=1;;i++){
		int j=key+i*(5-newValue%5);
		if(data[j%bucketSize].value==EMPTY){
			data[j%bucketSize].value=newValue;
			return true;
		}
	}
	return false;
}

bool DoubleHashing::clearData(){
	if(bucketSize!=0){
		delete[] data;
		return true;
	}
	else
		return false;

}




