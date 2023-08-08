#ifndef STACK_H_
#define STACK_H_


class Stack{
private:
	int list[1024];
	int num;

public:
Stack();
void push(int element);
int pop();
int top();
bool empty();

};


#endif
