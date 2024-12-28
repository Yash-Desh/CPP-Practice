// Author : Yash Deshpande
// Date : 26-01-2022

/* 

Q. Program to print the Pascal's Triangle

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

*/

#include <iostream>
using namespace std;

int factorial(int num)
{   
    int fact=1;
    for(int i=1; i<= num; i++)
    {
        fact*=i;
    }
    return fact;
}

int main()
{
    int rows;
    cin>>rows;

    for(int i=0; i<= rows; i++)
    {
        for(int j= 0; j<=i; j++)
        {
            cout<<factorial(i)/(factorial(j)*factorial(i-j))<<" ";
        }
        cout<<endl;
    }
    return 0;
}