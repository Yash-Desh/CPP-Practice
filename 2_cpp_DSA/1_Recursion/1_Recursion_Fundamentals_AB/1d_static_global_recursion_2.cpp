// Author : Yash Deshpande 
// Date : 05-04-2022
// Tutor : Abdul Bari

// Q. To deal with global variables in recursion

#include <iostream>
using namespace std;

int  x = 0;    // global variable declared

int func2 (int n)
{
    if (n>0)
    {
        x++;
        return func2(n-1) + x;
    }
    return 0;
}

int main()
{
    int a = 5;
    cout<<func2(a)<<endl;  // x = 0 at the very beginning

    cout<<func2(a)<<endl;  // x = 5 at the beginning from the previous function call
    return 0;
}
