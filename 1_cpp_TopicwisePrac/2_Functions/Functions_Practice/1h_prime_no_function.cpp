// Author : Yash Deshpande
// Date : 26-01-2022

// Q. Program to print all prime numbers between 2 given numbers using functions

#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a,b;
    cin>>a>>b;

    for(int i=a; i<=b; i++)
    {
        if(is_prime(i))
        {
            cout<<i<<endl;
        }
    }

    return 0;
}