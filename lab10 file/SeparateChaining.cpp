
#include <iostream>
#include "SeparateChaining.h"
using namespace std;

SeparateChaining::SeparateChaining(int size): Hashing(size),data(NULL){
	reset(size);
}

SeparateChaining::~SeparateChaining(){
	clearData();
}


void SeparateChaining::reset(int newSize){
	if(data != NULL)
		clearData();

	//create the hash table
	data = new ChainingElem[newSize];
	for(int i = 0; i < newSize; i++){
		data[i].value = EMPTY;			//NOTE: please do not store any other data here
		data[i].next = NULL;	 		//the pointer pointing to the linked list
	}
	bucketSize=newSize;
}

void SeparateChaining::print(){
	cout<<"[";
	for(int i = 0; i < bucketSize; i++){
		if(data[i].next == NULL){
			cout<<"_";
			if(i != bucketSize -1){
				cout<<",";
			}
		}
		else{
			ChainingElem *tmp = data[i].next;
			while(tmp != NULL){
				if(tmp != data[i].next){ //the value is not the first element of the linked list
					cout<<"->";
				}
				cout<<tmp->value;
				tmp = tmp->next;
			}
			cout<<",";
		}
	}
	cout<<"]"<<endl;
}


//TODO: Implement the hash function and return the location in which new value will be inserted
int SeparateChaining::getIndexByhashing(int keyValue){
	int key=keyValue%bucketSize;
	return key;
}



//TODO: Implement the function that will insert the new value into the hash table
bool SeparateChaining::insert(int newValue){
	int key=newValue%bucketSize;
	//ChainingElem *ptr=&data[key];
	if(data[key].next==NULL){
		ChainingElem *p=new ChainingElem;
		data[key].next=p;
		p->value=newValue;
		p->next=NULL;
		return true;
	}
	else if(data[key].next!=NULL){
		//ChainingElem* p=new ChainingElem;
		//p->next=NULL;
		//p->value=newValue;
	    ChainingElem *ptr=data[key].next;
	    ChainingElem *pp=data[key].next;
	   while(ptr!=NULL){
		   pp=ptr;
		   ptr=ptr->next;
	   }
	    //ptr=p;
	   pp->next=new ChainingElem;
	   ptr=pp->next;
	   ptr->value=newValue;
	   ptr->next=NULL;
	    return true;

	}
	return false;

}



//TODO: Implement the function that clear the hash table
//just return true after deletion; you may return false if the data is already deleted when this function is called
bool SeparateChaining::clearData(){
	int num=0;
	for(int i=0;i<bucketSize;i++){
		ChainingElem *ptr= &data[i];
		if(ptr==NULL){
			num++;
			continue;
		}
		else if(ptr->next==NULL)
			delete ptr;
		else
			delete[]ptr;
	}
	if(num==bucketSize)
		return false;

	return true;
}










