// Author : Yash Deshpande 
// Date : 05-04-2022
// Tutor : Abdul Bari

// Video 1 : How recursion works(Tracing)

#include <iostream>
using namespace std;

void func2(int n)
{
    if (n>0)
    {
        func2(n-1);    
        cout<<n<<endl;     // Executed at returning time
    }
}

int main()
{
    int x = 6;
    func2(x);

    return 0;
}