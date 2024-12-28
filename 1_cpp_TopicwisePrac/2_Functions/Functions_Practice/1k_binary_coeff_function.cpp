// Author : Yash Deshpande
// Date : 26-01-2022

/* 

Q. Program to find the binary coefficient nCr of a given number

nCr = n!/(r! * (n-r)!)

*/

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
    int n,r;
    cin>>n>>r;
    int ans = factorial(n)/(factorial(r)*factorial(n-r));
    cout<<n<<"C"<<r<<" = "<<ans;
    return 0;
}