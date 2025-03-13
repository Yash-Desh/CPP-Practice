// Author : Yash Deshpande
// Date : 08-09-2022
// Topic : Strings
// Tutor : Love Babbar
// Link : https://leetcode.com/problems/permutation-in-string/

#include <bits/stdc++.h>
using namespace std;

///////////////////////////
// Sliding Window Approach
///////////////////////////

// function to check if 2 arrays are identical
bool checkIfEqual(int a[], int b[])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}


bool checkInclusion(string s1, string s2)
{
    // hash map to store frequency info of s1
    int hash1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        hash1[index]++;
    }

    // hash table of the 1st window
    int hash2[26] = {0};
    int windowSize = s1.length();
    int i = 0;
    for (i = 0; i < windowSize && i < s2.length(); i++)
    {
        int index = s2[i] - 'a';
        hash2[index]++;
    }

    if (checkIfEqual(hash1, hash2))
    {
        return 1;
    }

    while (i < s2.length())
    {
        int index = s2[i] - 'a';
        hash2[index]++;
        int oldIndex = s2[i - windowSize] - 'a';
        hash2[oldIndex]--;
        i++;

        if (checkIfEqual(hash1, hash2))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    return 0;
}