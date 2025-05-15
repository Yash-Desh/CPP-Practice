// Author : Yash Deshpande
// Date : 20-03-2025
// Tutor : Luv

/*
Given a number N. Print its factorial
Constraints 
1 <= N <= 100
print answer%M where M = 10^9 + 7
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int M = 47;
    long long fact = 1;
    for(int i=2; i<=n; i++)
    {
        fact = (fact * i)%M;
    }
    cout<<fact<<endl;
    return 0;
}

/*
What is the significance of 10^9 + 7
10^9 is a value very close to the maximum value of an integer.
Taking a modulo with this value confirms that the result can be stored inside an int

10^9 is a prime number whose Multiplicative inverse can be determined. This is helpful & will be 
explained in greater depth by Luv in further videos 



*/