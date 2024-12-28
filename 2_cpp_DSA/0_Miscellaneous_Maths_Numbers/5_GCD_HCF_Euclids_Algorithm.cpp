// Author : Yash Deshpande
// Date : 08-07-2022
// Tutor : Love Babbar

// ######################## Euclids Algorithm to calculate GCD/HCF ########################

#include <iostream>
using namespace std;

// My Approach : Brute Force
// TLE
// TC : O(N) ... where N is the min(A,B)
// SC : O(1)
int gcd(int A, int B)
{
    // code here
    int limit = min(A, B);
    int ans = 1;
    for (int i = 2; i <= limit; i++)
    {
        if (A % i == 0 && B % i == 0)
        {
            ans = i;
        }
    }
    return ans;
}





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



// Euclid's Algorithm : Recursive Approach





int main()
{

    return 0;
}