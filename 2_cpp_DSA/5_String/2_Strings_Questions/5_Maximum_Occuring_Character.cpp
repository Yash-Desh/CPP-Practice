// Author : Yash Deshpande
// Date : 06-09-2022
// Topic : Strings
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;



// Using Hash
// TC : O(N)
// SC : O(1)

// Function to find the maximum occurring character in a string.
char getMaxOccuringChar(string s)
{
    // Your code here
    // create hash table storing the occurence count of each alphabet
    int hash[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        // for lowercase letters
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            hash[s[i] - 'a']++;
        }
        // for uppercase letters
        else
        {
            hash[s[i] - 'A']++;
        }
    }

    // find the char to occur max times
    int max = -1, ans = -1;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max)
        {
            max = hash[i];
            ans = i;
        }
    }
    return 'a' + ans;
}

int main()
{

    return 0;
}