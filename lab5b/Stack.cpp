hjkwe#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(){
	num=0;
}

void Stack::push(int element){
	if(num>=1024)
		return ;
	list[num]=element;
	num++;
}

int Stack::pop(){

	int a= list[num-1];
     if(num==0)
    	 return -1;

      else if(num==1)
    	 num=0;
       else
    	 num--;
     return a;
}

int Stack::top(){
	if(num==0){
		return-1;
	}
	else
		return list[num-1];
}

bool Stack::empty(){
	if(num==0)
		return true;
	else
		return false;
}










