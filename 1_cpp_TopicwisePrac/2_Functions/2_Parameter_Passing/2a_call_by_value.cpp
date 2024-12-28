// Author : Yash Deshpande
// Date : 25-01-2022

#include<iostream>
using namespace std;


// Call by value
void swap(int a, int b){ //temp a b
    int temp = a;        //4   4  5   
    a = b;               //4   5  5
    b = temp;            //4   5  4 
}


int main(){
    int x1 =4, y1=5;
    
    // Initial values of x1 and y1 
    cout<<"The value of x1 is "<<x1<<" and the value of y1 is "<<y1<<endl;
    
    swap(x1,y1);  // This will NOT swap a and b

    // After calling swap
    cout<<"The value of x1 is "<<x1<<" and the value of y1 is "<<y1<<" after swap()"<<endl<<endl; 
    
   
    
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. swap() function is the best example of implementing call by reference

2. Remember the 3 cups analogy for the swap() function

3. When the call by value method is used it doesn’t change the actual values because copies of actual values(i.e actual parameters) 
   are sent(i.e copied) to the function (i.e formal parameters).

4. Any changes made to the formal parameters will not reflect on the actual parameters.

5. When the value of actual parameter need not be changed, call by value is utilized.

6. Also when the function is just processing the data & returning some result pass by value is used.








*/
