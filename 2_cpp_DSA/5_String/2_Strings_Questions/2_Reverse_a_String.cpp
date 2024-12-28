// Author : Yash Deshpande
// Date : 06-09-2022
// Topic : Strings
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// #######################################
// Approach - 1 : Using 2-pointer Approach
// Optimal Approach, AC
// TC : O(N)
// SC : O(1)
// #######################################

void reverseString(vector<char> &s)
{
    int s1 = 0;           // ptr to start of array
    int r = s.size() - 1; // ptr to end of array
    while (s1 < r)
    {
        // swap
        // swap() is a built-in function of std library
        swap(s[s1++], s[r--]);
    }
}

// Approach-2 , AC
// Using Stack
// TC = O(N)
// TC = O(N)
char *reverse(char *S, int len)
{
    // code here
    stack<char> st;
    int i = 0;
    for (i = 0; S[i] != '\0'; i++)
    {
        st.push(S[i]);
    }

    i = 0;
    while (!st.empty())
    {
        S[i++] = st.top();
        st.pop();
    }
    return S;
}

int main()
{

    return 0;
}