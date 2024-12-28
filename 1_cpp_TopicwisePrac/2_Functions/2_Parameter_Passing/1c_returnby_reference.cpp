// Author : Yash Deshpande
// Date : 25-01-2022
// Tutor : Code With Harry , Love Babbar

#include <iostream>
using namespace std;

int & swapReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return a;
}

int & func (int n)
{
    int &p = n;
    return p;
}

int main()
{
    int x =4, y=5;
    
    // // Initial values of x and y 
    // cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;

    // swapReference(x,y) = 76;
    // cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl; 

    cout<<func(x);

    return 0;
}