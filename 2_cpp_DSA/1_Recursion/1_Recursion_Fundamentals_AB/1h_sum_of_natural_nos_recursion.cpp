// Author : Yash Deshpande 
// Date : 11-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

// M1 : Recursive Approach
int sum1 (int n)
{
    if (n==0)
    {
        return 0;
    }
    else 
    {
        return sum1(n-1) +n;
    }
}


// M2 : Iterative (Loops) Approach
int sum2(int n)
{
    int i, s=0;
    for(i = 1; i <= n; i++)
    {
        s = s+i;
    }
    return s;
}


// M3 : Formula
int sum3(int n)
{
    return (n*(n+1))/2;
}


int main()
{
    int res1 = sum1(5);   // Recursive 
    cout<<res1<<endl;

    int res2 = sum2(5);  // Iterative
    cout<<res2<<endl;

    int res3 = sum3(5);  // Formula
    cout<<res3<<endl;
    
    return 0;
}

/*

M 1.2 : Recursive Approach

int sum (int n)
{
    if (n>0)
    {
        return n + sum(n-1);
    }
    return 0;
}


*/