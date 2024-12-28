// Author : Yash Deshpande 
// Date : 05-04-2022
// Tutor : Abdul Bari

// Q. To deal with static variables in recursion

#include <iostream>
using namespace std;

int func1 (int n)
{
    static int  x = 0;    // static variable declared
    if (n>0)
    {
        x++;
        return func1(n-1) + x;
    }
    return 0;
}

int main()
{
    int a = 5;
    cout<<func1(a);
    return 0;
}