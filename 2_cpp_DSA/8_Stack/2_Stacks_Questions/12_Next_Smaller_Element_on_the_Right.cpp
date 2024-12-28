// Author : Yash Deshpande
// Date : 3-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach - 1 : Brute Force
// TC : O(N^2)
// SC : O(1)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int minimum = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                minimum = arr[j];
                break;
            }
        }
        ans.push_back(minimum);
    }
    return ans;
}

// Approach - 2
// TC : O(N)
// SC : O(N)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

// Approach - 2, different implementation
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(i);

        else
        {
            if (arr[i] >= arr[st.top()])
                st.push(i);

            else
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                {
                    ans[st.top()] = arr[i];
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