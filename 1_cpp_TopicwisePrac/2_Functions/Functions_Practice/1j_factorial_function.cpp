// Author : Yash Deshpande
// Date : 26-01-2022

// Q. Program to find the factorial of the given number

#include <iostream>
using namespace std;

int factorial(int num)
{   
    int fact=1;
    for(int i=1; i<= num; i++)
    {
        fact*=i;
    }
    return fact;
}

int main()
{
    int n;
    cin>>n;
    
    int ans= factorial(n);
    cout<<n<<"! = "<<ans;
    return 0;
}