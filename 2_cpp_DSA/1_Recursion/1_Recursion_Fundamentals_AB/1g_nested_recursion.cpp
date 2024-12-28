// Author : Yash Deshpande 
// Date : 11-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

int fun (int n)
{
    if(n>100)
    {
        return n-10;
    }

    else 
    {
        return fun(fun(n+11));
    }
}

int main()
{
    int x ;
    x = fun(95);
    cout<<x;
    return 0;
}