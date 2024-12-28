// Author : Yash Deshpande
// Date : 08-01-2022

// Q. Implement a simple calculator using switch

#include <iostream>
using namespace std;

int main()
{
    float n1,n2;  // operands
    cin>>n1>>n2;
    
    char op;   // operator
    cout<<"Input an Operator : ";
    cin>>op;
    
    switch (op)
    {
    case '+':
        cout<<"n1 + n2 = "<<n1+n2;
        break;
    case '-':
        cout<<"n1 - n2 = "<<n1-n2;
        break;
    case '*':
        cout<<"n1 * n2 = "<<n1*n2;
        break;
    case '/':
        cout<<"n1 / n2 = "<<n1/n2;
        break;

    default:
        cout<<"Enter another Operator";
        break;
    }

    return 0;
}