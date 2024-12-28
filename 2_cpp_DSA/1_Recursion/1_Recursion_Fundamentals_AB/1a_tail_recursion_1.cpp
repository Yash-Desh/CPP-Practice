// Author : Yash Deshpande 
// Date : 05-04-2022
// Tutor : Abdul Bari

// Video 1 : How recursion works(Tracing)

#include <iostream>
using namespace std;

void func1(int n)
{
    if (n>0)
    {
        cout<<n<<endl;    // Executed at calling time 
        func1(n-1);
    }
}

int main()
{
    int x = 6;
    func1(x);
    return 0;
}