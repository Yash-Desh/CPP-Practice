// Author : Yash Deshpande
// Date : 08-09-2022
// Topic : Strings
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// TC : O(N)
// SC : O(1)
int compress(vector<char> &chars)
{
    int i = 0;
    int len = chars.size();
    int ansIndex = 0; // stores the number of elements in chars after modification
    while (i < len)
    {
        int j = i + 1;
        while (j < len && chars[i] == chars[j]) // j is always checked to prevent out                                                        of bounds
        {
            j++;
        }
        // terminating conditions for the this while loop are:
        // u traversed to the end of the loop
        // u encountered a different element than chars[i]
        chars[ansIndex++] = chars[i];
        if (j - i > 1)
        {
            string cnt = to_string(j - i);
            for (char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{

    return 0;
}