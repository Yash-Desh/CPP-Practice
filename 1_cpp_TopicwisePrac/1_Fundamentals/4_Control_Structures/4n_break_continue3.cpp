// Author : Yash Deshpande
// Date : 24-01-2022

// Q. Program to print numbers from 0-100 except those divisible by 3

#include <iostream>
using namespace std;

int main()
{
    for(int i = 0; i <= 100; i++) 
    {
        if(i%3 == 0)
        {
            continue;
        }
        cout<<i<<endl;
    }
    return 0;
}