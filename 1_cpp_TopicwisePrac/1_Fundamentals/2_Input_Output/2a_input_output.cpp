// Author : Yash Deshpande
// Date : 07-01-2022

#include <iostream>
using namespace std;

int main()
{
    //'<<' is the insertion operator 
    //'>>' is the extraction operator
    int num1,num2,num3;
    cout<<"Enter the value of num1 :";              // string output
    cin>>num1;                                      // single input                       
    cout<<"Enter the value of num2 and num3 :\n";
    cin>>num2>>num3;                                // multiple input

    int sum = num1 +num2 +num3;
    cout<<"The sum of 3 numbers = "<<sum;            // using variables & strings together in output
    return 0;
}

/*

##############################################Extra Notes#####################################################

A. When taking multiple input values at the same time there are 2 possible methods
    1. Press "enter" after typing every input 
    2. Space seperated input 


*/