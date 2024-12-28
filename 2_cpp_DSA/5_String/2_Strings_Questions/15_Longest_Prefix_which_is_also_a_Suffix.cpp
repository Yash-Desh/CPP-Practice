// Author : Yash Deshpande
// Date : 10-09-2022
// Topic : Strings
// Tutor : Coding Ninjas , 450 DSA

#include <bits/stdc++.h>
using namespace std;

// Brute Force  :  TLE
// TC = O(N^2)
// SC = O(N)

int lps(string s)
{
    // Your code goes here
    string prefix = "";
    string suffix = "";
    int n = s.size();
    int maxSize = 0;
    for (int i = 0; i < n - 1; i++)
    {
        prefix.push_back(s[i]);
        suffix = s[n - i - 1] + suffix;
        if (prefix == suffix)
        {
            maxSize = prefix.size();
        }
    }
    return maxSize;
}

// KMP Algo
// TC = O(N)
// SC = O(N)
void makeLPS(string s, vector<int> &lps)
{
    int n = s.size();
    int i = 1;
    int prev = 0;

    while (i < n)
    {
        // match found
        if (s[i] == s[prev])
        {
            prev++;
            lps[i] = prev;
            i++;
        }

        // match not found
        else
        {
            if (prev == 0)
            {
                // prev = 0
                lps[i] = 0;
                i++;
            }
            else
            {
                prev = lps[prev - 1];
            }
        }
    }
}

int lps(string s)
{
    // Your code goes here
    int n = s.size();
    vector<int> lps(n, 0);

    makeLPS(s, lps);
    return lps[n - 1];
}

int main()
{

    return 0;
}