// Author : Yash Deshpande
// Date : 1-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Approach-1 , AC
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