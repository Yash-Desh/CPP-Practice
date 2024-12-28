// Author : Yash Deshpande 
// Date : 11-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;


// TC : O(N)

// M1 : Recursive Approach
int fact1 (int n)   
{
    if (n==0)     // -> Cannot handle negative numbers
    {
        return 1;
    }
    else
    {
        return fact1(n-1) * n;
    }
}


// M2 : Iterative Approach
int fact2 (int n)
{
    int f = 1;
    int i;
    for (i= 1; i <= n; i++)
    {
        f = f*i;
    }
    return f;
}


int main()
{
    cout<<fact1(6)<<endl;  // Recursive 

    cout<<fact2(6)<<endl;   // Iterative 
    return 0;
}