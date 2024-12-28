// Author : Yash Deshpande
// Date : 25-01-2022

#include<iostream>
using namespace std;

// *********************Function prototype**************************

// return_type function_name (arguments);

// int sum(int a, int b);           //--> Acceptable
// int sum(int a, b);               //--> Not Acceptable 
int sum(int, int);                  //--> Acceptable 


// void display(void);              //--> Acceptable 
void display();                     //--> Acceptable 

int main(){
    int num1, num2;
    
    cout<<"Enter first number"<<endl;
    cin>>num1;
    
    cout<<"Enter second number"<<endl;
    cin>>num2;
    
    // num1 and num2 are actual parameters
    cout<<"The sum is "<<sum(num1, num2);
    display();
    return 0;
}

int sum(int a, int b){
    // Formal Parameters a and b will be taking values from actual parameters num1 and num2.
    int c = a+b;
    return c;
}

// void function
void display(){
    cout<<"\nHello, Good Morning";
}
/*

##############################################Extra Notes#####################################################

1. Functions are the main part of top-down structured programming. We break the code into small pieces and make 
   functions of that code. Functions help us to reuse the code easily. 

   -> FUNCTION PROTOTYPE

2. The function prototype is the template of the function which tells the details of the function e.g(name, parameters)
   to the compiler. 

3. Function prototypes help us to define a function after the function call. 

4. Here we have made a function prototype of the function “sum”, this function prototype will tell the compiler that 
   the function “sum” is declared somewhere in the program which takes two integer parameters and returns an integer 
   value.

   -> FUNCTION PARAMETERS

5. Formal Parameters : The variables which are declared in the function are called a formal parameter.

6. Actual Parameters : The values which are passed to the function are called actual parameters.

7. Values of the actual parameters are copied into the formal parameters.

8. A function may neither return value (i.e. void function) nor take parameters.

9. void as a return type means that this function will not return anything. 

10. return_type function_name (void) --> this function has no parameters.


*/