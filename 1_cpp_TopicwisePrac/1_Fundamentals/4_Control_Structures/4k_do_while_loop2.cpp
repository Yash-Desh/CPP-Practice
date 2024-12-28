// Author : Yash Deshpande
// Date : 24-01-2022

// Q. Program to accept only positive numbers and print

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    do
    {
        cout<<n<<endl;
        cin>>n;

    }while(n>0);  // Notice the difference between file 4i & file 4k
                  // 4k runs even if the initial input is non-positive but 4i does't

    return 0;
}