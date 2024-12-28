// Author : Yash Deshpande
// Date : 26-01-2022

// Q. Program to reverse a given number

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter a number to reverse : ";
    cin>>num;

    int dividend = num;  // To preserve the original number
    int rev_num = 0;

    while (dividend != 0)
    {
        int last_digit = dividend %10;
        rev_num = rev_num*10 + last_digit;
        dividend /= 10;
    }
    
    cout<<"Reverse of "<<num<<" = "<<rev_num<<endl;

    return 0;
}