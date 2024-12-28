// Author : Yash Deshpande
// Date : 08-01-2022

// Q. Write a Program to find the maximum of 3 given numbers 

#include <iostream>
using namespace std;

int main()
{
    int num1,num2,num3;
    cin>>num1>>num2>>num3;

    if (num1>num2)
    {
        if (num1>num3)
        {
            cout<<"The greatest value = "<<num1;
        }
        else 
        {
            cout<<"The greatest value = "<<num3;
        }
    }
    else
    {
        if (num2>num3)
        {
            cout<<"The greatest value = "<<num2;
        }
        else 
        {
            cout<<"The greatest value = "<<num3;
        }
    }
    return 0;
}