// Author : Yash Deshpande 
// Date : 11-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

void funB (int n);  // Function prototype must if it is called before its definition

void funA (int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        funB(n-1);  // call to function funB before its definition
    }
}

void funB (int n)
{
    if(n>1)
    {
        cout<<n<<" ";
        funA(n/2);
    }
}

int main()
{
    int x = 20;
    funA(x);

    return 0;
}