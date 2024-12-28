// Author : Yash Deshpande
// Date : 24-01-2022

// Q. Program to print all prime numbers till given number

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;

    int cnt;
    for(cnt = 2; cnt <= num; cnt++)
    {
        int factor;
        for(factor=2; factor<cnt; factor++)
        {
            if(cnt%factor == 0)
            {
                break;
            }
        }
        if(factor== cnt)
        {
            cout<<cnt<<endl;
        }
    }
    return 0;
}