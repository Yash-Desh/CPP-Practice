// Author : Yash Deshpande
// Date : 24-01-2022

// Q. Program to accept only positive numbers and print

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    while(n>0)
    {
        cout<<n<<endl;
        cin>>n;
    }
    return 0;
}