/*
 * Stack.h
 *
 *  Created on: 2019Äê10ÔÂ22ÈÕ
 *      Author: MECHREVO
 */

#ifndef STACK_H_
#define STACK_H_

const int SSIZE = 1024;

//First-in-last-out
class Stack
{
private:
	int content[SSIZE];
	int m;

public:
	Stack();
	int pop();
	void push(int element);
	int top();
	bool empty();
};





#endif /* STACK_H_ */
