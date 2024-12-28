// Author : Yash Deshpande
// Date : 10-07-2023
// Tutor : Love Babbar Weekly Test - 2

#include <bits/stdc++.h>
using namespace std;

/*
Notice that 1s at a higher index will cost more than all the previous
1s combined. So 11100 will cost LESS than 00010 irrespespective of the
value of P

*/

// Brute Force : Trying each combination
// TC : O(N^3)
string binaryShopping(string S, int P)
{
    string ans = S;
    int n = S.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // Flipping the bit at index 'i'.
            if (S[i] == '0')
            {
                S[i] = '1';
            }
            else
            {
                S[i] = '0';
            }

            // Flipping the bit at index 'j'.
            if (S[j] == '0')
            {
                S[j] = '1';
            }
            else
            {
                S[j] = '0';
            }

            for (int k = n - 1; k >= 0; k--)
            {
                if (S[k] == '0' && ans[k] == '1')
                {
                    // Current 'S' has lower cost so assign 'ans' to 'S'.
                    ans = S;
                    break;
                }
                else if (S[k] == '1' && ans[k] == '0')
                {
                    // 'ans' has lower cost.
                    break;
                }
            }

            // Flipping the bit at index 'i' to get back the original one.
            if (S[i] == '0')
            {
                S[i] = '1';
            }
            else
            {
                S[i] = '0';
            }

            // Flipping the bit at index 'j' to get back the original one.
            if (S[j] == '0')
            {
                S[j] = '1';
            }
            else
            {
                S[j] = '0';
            }
        }
    }
    return ans;
}

// My Approach : Sub-Optimal
// My code does the same as the optimal code but in a slightly confused manner
// TC : O(N)
string binaryShopping(string S, int P)
{
    // Write your code here.

    // corner case : if string size is 1
    if (S.size() == 1)
        return S;

    // cnt to store number of operations performed
    // at max 2 operations can be performed
    int cnt = 0;

    // boolean to store whether any index had a flip of value
    bool flipped = 0;

    // flip the highermost indices to 0
    for (int i = S.size() - 1; i >= 0 && cnt < 2; i--)
    {
        if (S[i] == '1')
        {
            S[i] = '0';
            cnt++;
            flipped = 1;
        }
    }

    // if all the indices have '0'
    // eg. 0000 , 00000 etc
    if (!flipped)
        return S;

    // Flip the lowermost indices to 1
    for (int i = 0; i < S.size() && cnt < 2; i++)
    {
        if (S[i] == '0')
        {
            S[i] = '1';
            cnt++;
        }
    }

    return S;
}

// Optimal Approach
// TC : O(N)
// SC : O(1)

string binaryShopping(string S, int P)
{
    int cn = 0;
    int n = S.size();

    for (int i = 0; i < n; i++)
    {
        if (S[i] == '1')
        {
            // Counting the number of '1'.
            cn++;
        }
    }

    if (cn >= 2)
    {

        cn = 2;
        // Converting last two '1' to '0'.
        for (int i = n - 1; i >= 0; i--)
        {
            if (S[i] == '1')
            {
                S[i] = '0';
                cn--;
            }
            if (cn == 0)
            {
                break;
            }
        }
    }
    else if (cn == 1)
    {
        // Converting the only index having '1' to '0'.
        for (int i = 0; i < n; i++)
        {
            if (S[i] == '1')
            {
                S[i] = '0';
                break;
            }
        }

        // Converting the first index to '1'.
        S[0] = '1';
    }
    return S;
}

int main()
{

    return 0;
}