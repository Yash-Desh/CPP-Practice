// Author : Yash Deshpande
// Date : 24-01-2022

// Q. Program to print all the prime numbers between given 2 numbers

#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cout<<"Enter Lower Limit : ";
    cin>>a;
    cout<<"Enter Upper Limit : ";
    cin>>b;
    
    for(int cnt = a; cnt <= b; cnt++)
    {
        int factor;
        for (factor =2; factor < cnt; factor++)
        {
            if(cnt%factor ==0)
            {
                break;
            }
            
        }
        if(factor == cnt)
        {
            cout<<cnt<<endl;
        }
        
    }

    return 0;
}