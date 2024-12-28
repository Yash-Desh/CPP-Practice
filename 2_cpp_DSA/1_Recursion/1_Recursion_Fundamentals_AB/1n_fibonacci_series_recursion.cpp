// Author : Yash Deshpande 
// Date : 11-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

// Note : Fibonacci sequence is zero-indexed
// fib(0) = 0



// M1 : Iterative Approach
int ifib(int n)
{
    int t0=0, t1 = 1,s;
    if(n<=1)
    {
        return n;
    }
    else
    {
        for(int i = 2; i<=n; i++)
        {
            s = t0+t1;
            t0 = t1;
            t1 = s;
        }
        return s;
    }
}



// M2 : Recursive Approach
int rfib(int n)
{
    if (n<= 1)
    {
        return n;
    }
    else 
    {
        return rfib(n-2) + rfib(n-1);
    }
}

  
// M3 : Recursive Approach with Memoization

// In computing, memoization or memoisation is an optimization technique 
// used primarily to speed up computer programs by storing the results of 
// expensive function calls and returning the cached result when the same 
// inputs occur again.

int F[10]; 

int mfib(int n)
{
    if (n<=1)
    {
        F[n] = n;
        return n;
    }
    else 
    {
        if (F[n-2] == -1)
        {
            F[n-2] = mfib(n-2);
        }

        if (F[n-1] == -1 )
        {
            F[n-1] = mfib(n-1);
        }
        F[n] = F[n-2] +F[n-1];
        return F[n-2] + F[n-1];
    }
}


int main()
{   
    // Iteration
    cout<<ifib(6)<<endl;

    // Recursion
    cout<<rfib(7)<<endl;

    // Memoization

    // Initializing all the elements in the global array = -1
    for(int i=0; i<10;i++)
    {
        F[i] = -1;
    }
    cout<<mfib(8)<<endl;
    return 0;
}