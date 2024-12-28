// Author : Yash Deshpande
// Date : 26-01-2022

// Q. Program to check if a number is prime or not  : [Logic 2 using sqrt]

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;

    bool flag;

    for(int factor =2; factor<= sqrt(num); factor++)
    {
        if(num%factor == 0)
        {
            cout<<num<<" is Non Prime"<<endl;
            flag =1;    
            break;
        }
    }

    // To check whether the loop exited after encountering 
    // a break statement or after running out of iterations
    if(flag == 0 )
    {
        cout<<num<<" is Prime"<<endl;
    }
    
    return 0;
}