// Author : Yash Deshpande
// Date : 24-01-2022

// Q. Program to check if a number is prime or not

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;

    int factor;
    for(factor =2; factor<num; factor++)
    {
        if(num%factor == 0)
        {
            cout<<num<<" is Non Prime"<<endl;
            break;
        }
    }

    // To check whether the loop exited after encountering 
    // a break statement or after running out of iterations
    if(factor == num )
    {
        cout<<num<<" is Prime"<<endl;
    }
    
    return 0;
}