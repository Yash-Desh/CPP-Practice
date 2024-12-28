// Author : Yash Deshpande
// Date : 22-03-2022

#include <iostream>
using namespace std;

// Call by reference using C++ reference Variables
void swapReferenceVar(int &a, int &b){ //temp a b
    int temp = a;        //4   4  5   
    a = b;               //4   5  5
    b = temp;            //4   5  4 
    // return a;
}

int main()
{
    int x3 =4, y3=5;
    
    // Initial values of x and y 
    cout<<"The value of x3 is "<<x3<<" and the value of y3 is "<<y3<<endl;

    swapReferenceVar(x3, y3); //This will swap a and b using reference variables


    // After calling swap
    cout<<"The value of x3 is "<<x3<<" and the value of y3 is "<<y3<<" after swapReferenceVar()"<<endl<<endl; 
    
    return 0;
}
/*

##############################################Extra Notes#####################################################

1. When the call by reference method is used it changes the actual values because references of actual values(i.e actual parameters)
   are sent to the function(i.e formal parameters).

2. Only available in C++.

3. Here the function swapReferenceVar() is not a seperate function from the main() function but a part of main() itself.
   Here the function swapReferenceVar() is not defined inside a seperate stack frame but it is in the same stack frame
   as the main().
   The machine code of the swapReferenceVar() is pasted inside the main() function and not seperately like a normal 
   function.
   Hence on the machine code level it sort of defeats the purpose of making a seperate function.

4. Hence call by reference must be used for smaller programs and with precaution.

*/