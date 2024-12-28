// Author : Yash Deshpande 
// Date : 11-04-2022
// Tutor : Abdul Bari

// Q. To write a program for the taylor series of e^x

#include <iostream>
using namespace std;

double e(int x, int n)   // n = number of terms we want for precision 
{
    static double p = 1, f = 1;
    double r;
    if(n==0)
    {
        return 1;
    }
    else
    {
        r = e(x, n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
    }
}

int main()
{
    cout<<e(1,10);
    return 0;
}