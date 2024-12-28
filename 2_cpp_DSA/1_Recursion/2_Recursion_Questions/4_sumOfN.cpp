// Author : Yash Deshpande 
// Date : 15-08-2022
// Tutor : Striver

// find the sum of the 1st n numbers

#include <iostream>
using namespace std;

// Parameterized Recursion
void sumN (int i, int sum)
{
    if(i < 1)
    {
        cout<<sum<<endl;
        return;
    }
    sumN(i-1, sum +i);
}


// functional recursion
int sumOfN (int n)
{
    if(n == 0)
        return 0;
    return n + sumOfN(n-1);
}

int main()
{
    // sumN(10, 0);
    cout<<sumOfN(9)<<endl;
    return 0;
}