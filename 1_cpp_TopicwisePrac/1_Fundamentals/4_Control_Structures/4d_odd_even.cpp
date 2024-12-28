// Author : Yash Deshpande
// Date : 08-01-2022

// Q.  Write a Program to find whether a given number is odd or even

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin>>num;
    if (num%2 ==0)    // '%' modulo operator gives the remainder in a division
    {
        cout<<num<<" is Even";
    }
    else
    {
        cout<<num<<" is ODD";
    }
    return 0;
}