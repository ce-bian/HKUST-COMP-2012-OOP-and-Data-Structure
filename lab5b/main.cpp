#include "Queue.h"
#include "Stack.h" // TODO: implement a stack using  an array in Stack.h and Stack.cpp (to be created by yourself)
#include <iostream>
using namespace std;

// checkBox: Determine whether the switch box is routable
bool checkBox(Queue pins)
{

    // TODO: Return true if it is routable, false otherwise
    // Use Stack to implement this part
	int size=pins.elementCount();
   Stack stack1;
   for(int i=0;i<size;i++){
	   stack1.push(pins.dequeue());
   }
   Stack stack2;
   stack2.push(stack1.pop());
   for(int i=0;i<size;i++){
	   int number=stack1.pop();
	   if(number==stack2.top())
		  stack2.pop();
		else
		   stack2.push(number);
   }
   return stack2.empty();
}

int main()
{
    int n;
    Queue pins;

    cout << "** Assumption: The number of pins is even and it is greater than or equal to  2 **" << endl ;

    cout << "Type number of pins in switch box: " ;
    cin >> n ;

    cout << "Type numbers for pins 1 through " << n << ": " ;
    int k;
    for (int i=0;i<n;i++)
    {
        cin >> k;
        pins.enqueue(k);
    }

    bool result = checkBox(pins);
    if ( result ) {
        cout << "The switch box is routable" << endl ;
    } else {
        cout << "The switch box is NOT routable" << endl ;
    }

    return 0;
}
