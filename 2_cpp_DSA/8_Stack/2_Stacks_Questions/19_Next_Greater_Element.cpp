// Author : Yash Deshpande
// Date : 20-08-2023
// Tutor : LUV

// NOTE : This qs can be solved in O(n^2) time using brute force
//        But by using stack , we can do it in O(n) time

#include <bits/stdc++.h>
using namespace std;

// function that returns the next greatest element (NGE)
// NOTE : To make the coding simpler , we will be pushing indexes into the stack
//        & not the actual values
vector<int> NGE(vector<int> v)
{
    vector<int> nge(v.size()); // vector that contains the nge of each element at corresponding index
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && (v[i] > v[st.top()]))
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);       // push current element index to stack
    }

    // when the stack contains some elements which don't hv a nge
    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }

    return nge;
}

int main()
{
    int n; // number of elements in the vector
    cin >> n;
    vector<int> v(n); // vector to store input

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans = NGE(v);
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" "<<(ans[i] == -1 ? -1 : v[ans[i]])<<endl;
    }

    return 0;
}