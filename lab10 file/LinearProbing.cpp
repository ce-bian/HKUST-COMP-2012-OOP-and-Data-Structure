# include <iostream>
#include "LinearProbing.h"
using namespace std;

LinearProbing::LinearProbing(int size):Hashing(size),data(NULL){
	reset(size);
}

LinearProbing::~LinearProbing()
{
	clearData();
}

void LinearProbing::reset(int newSize){
	if(data != NULL)
		clearData();

	//create the hash table
	data = new LinearElem[newSize];
	for(int i = 0; i < newSize; i++){
		data[i].value = EMPTY;			//NOTE: please do not store any other data here

	}
	bucketSize=newSize;
}

void LinearProbing::print(){
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

int LinearProbing::getIndexByhashing(int newValue){
	int key=newValue%bucketSize;
	   // int i=key;
	    if(data[key].value==EMPTY){
	    	return key;
	    }
	    for(int i=key+1;i<bucketSize+key+1;i++){
	    	if(data[i].value==EMPTY)
	    		return i;
	    }
	    	return -1;
}

bool LinearProbing::insert(int newValue){
	int key=newValue%bucketSize;
   // int i=key;
    if(data[key].value==EMPTY){
    	data[key].value=newValue;
    	return true;
    }
    for(int i=key+1;i<bucketSize;i++){
    	if(data[i].value==EMPTY){
    		data[i].value=newValue;
    		return true;
    	}
    }
    for(int i=0;i<key;i++){
    	if(data[i].value==EMPTY){
    	   data[i].value=newValue;
    	   return true;
    	  }
    }
    return false;

}

bool LinearProbing::clearData(){
      if(bucketSize!=0){
    	 delete[] data;
    	 return true;
      }
      else
    	  return false;


}



