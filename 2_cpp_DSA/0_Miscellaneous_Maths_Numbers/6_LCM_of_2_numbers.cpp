// Author : Yash Deshpande
// Date : 09-07-2022
// Tutor : Love Babbar


// ######################## LCM(A,B) * GCD(A,B) = A*B ########################


#include <iostream>
using namespace std;

// Babbar Approach : Optimal Approach
// Euclid's Algorithm : Iterative Approach
// TC : O(max(A,B))
// SC : O(1)
int gcd(int A, int B)
{
    // code here

    // when one of the number is zero
    if (A == 0)
        return B;

    if (B == 0)
        return A;

    // when both numbers are not equal
    while (A != B)
    {
        if (A > B)
            A = A - B;

        else if (B > A)
            B = B - A;
    }

    // when both numbes are equal
    return A;
}


int lcm(int A, int B)
{
    return (A*B)/gcd(A,B);
}

int main()
{
    
    return 0;
}