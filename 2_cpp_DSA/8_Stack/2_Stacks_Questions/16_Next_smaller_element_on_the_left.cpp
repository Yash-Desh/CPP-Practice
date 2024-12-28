// Author : Yash Deshpande
// Date : 12-08-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Babbar Approach
vector<int> leftSmaller(int n, int a[])
{
    // code here
    vector<int> ans(n);

    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st.top() >= a[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(a[i]);
    }
    return ans;
}

// My Approach -> Same as Babbar Approach
// But implemented differently
vector<int> leftSmaller(int n, int a[])
{
    // code here
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            st.push(i);

        else
        {
            if (a[i] >= a[st.top()])
                st.push(i);

            else
            {
                while (!st.empty() && a[i] < a[st.top()])
                {
                    ans[st.top()] = a[i];
                    st.pop();
                }
                st.push(i);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}