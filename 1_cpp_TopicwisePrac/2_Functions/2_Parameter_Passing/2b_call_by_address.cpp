// Author : Yash Deshpande
// Date : 22-03-2022

#include <iostream>
using namespace std;

// Call by reference using pointers
void swapPointer(int* a, int* b){ //temp a b
    int temp = *a;        //4   4  5   
    *a = *b;              //4   5  5
    *b = temp;            //4   5  4 
}


int main()
{
    int x2 =4, y2=5;
    
    // Initial values of x2 and y2 
    cout<<"The initial value of x2 is "<<x2<<" and the value of y2 is "<<y2<<endl<<endl;

    swapPointer(&x2, &y2); //This will swap a and b using pointer reference
    
    // After calling swap
    cout<<"The value of x2 is "<<x2<<" and the value of y2 is "<<y2<<" after swapPointer()"<<endl; 


    return 0;
}

/*

##############################################Extra Notes#####################################################

1. When the call by pointer method is used it changes the actual values because addresses of actual values(i.e actual parameters)
   are sent to the function (i.e formal parameters).

2. The formal parameters must be pointers & the actual parameters are address.

3. One function is able to access the variables of other function indirectly using pointers

4. Changes made to the formal parameters will be reflected in the actual parameters.

5. When to use : To make changes to the actual parameters 
                 Since only one value can be returned by a function, when we want to return / (change) multiple values 
                 When function parameters are user-definded variable datatypes , they must be sent as address 
*/