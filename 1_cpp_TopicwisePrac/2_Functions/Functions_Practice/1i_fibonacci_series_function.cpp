// Author : Yash Deshpande
// Date : 26-01-2022

// Q. Program to print all the terms in fibonacci sequence till a given term using functions

#include <iostream>
using namespace std;

void fib(int num)
{
    int t1 = 0;
    int t2 = 1;
    int next_term ;

    for(int i=1; i<=num; i++)
    {
        cout<<t1<<endl;
        next_term = t1 + t2;
        t1 = t2;
        t2 = next_term;
    }
}


int main()
{
    int n;
    cin>>n;
    fib(n);
    return 0;
}