#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	m = 0;
}

int Stack::pop()
{
	if(m<=0)
	{
		cerr << "Stack is empty!" << endl;
		return -1;
	}

	m--;
	return content[m];
}

void Stack::push(int element)
{
	if(m>=SSIZE)
	{
		cerr << "Stack is full!" << endl;
		return;
	}

	content[m] = element;
	m++;
}

int Stack::top()
{
	if(m<=0)
	{
		return -1;
	}

	return content[m-1];
}

bool Stack::empty()
{
	return (m<=0);
}
