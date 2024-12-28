// Author : Yash Deshpande
// Date : 07-04-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// ########################
// Approach - 1 : Stack
// Babbar Approach
// TC : O(N)
// SC : O(K)
// ########################

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.

    // Step-1 : Pop 1st k elements from queue & push into stack
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        st.push(val);
    }

    // Step-2 : Fetch from stack and push into queue
    while(!st.empty())
    {
        int val = st.top();
        q.push(val);
        st.pop();
    }


    // Step-3 : Fetch 1st n-k elements from queue & push back
    for (int i = 0; i < q.size() - k; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main()
{

    return 0;
}