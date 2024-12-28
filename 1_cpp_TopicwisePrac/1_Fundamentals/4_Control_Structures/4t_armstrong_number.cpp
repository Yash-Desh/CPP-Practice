// Author : Yash Deshpande
// Date : 26-01-2022

/* 

Q. Program to find whether a given number is Armstrong number or not 
Example of an Armstrong number is : e.g. 153 = 1^3 + 5^3 + 3^3
                                             = 1  + 125  + 27
                                             = 153

Sum of the cubes of the digit is equal to the number itself

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout<<"Enter a number to find whether a given number is Armstrong number or not : ";
    cin>>num;

    int cube_sum =0;
    int pres_num = num;  // To preserve the given number

    while(num !=0)
    {
        int last_digit = num%10;
        cube_sum += pow(last_digit,3);
        num /= 10; 
    }

    if (pres_num == cube_sum)
    {
        cout<<"Armstrong Number"<<endl;
    }
    else{
        cout<<"Not Armstrong Number"<<endl;
    }

    return 0;
}