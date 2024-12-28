// Author : Yash Deshpande
// Date : 12-04-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// ########################
// Approach - 1 : Brute Force, AC
// My Approach
// TC : O(N)
// SC : O(N)
// ########################
vector<int> rearrangeQueue(queue<int> &q)
{
    vector<int> temp;
    vector<int> ans;

    // Push all queue elements into a vector
    while (!q.empty())
    {
        temp.push_back(q.front());
        q.pop();
    }

    // Copy elements of the vector into another vector in an interleaved manner
    for (int i = 0, j = temp.size() / 2; i < temp.size() / 2 && j < temp.size(); i++, j++)
    {
        ans.push_back(temp[i]);
        ans.push_back(temp[j]);
    }
    return ans;
}

// ########################
// Approach - 2 : Using Queue, AC
// Babbar Approach
// TC : O(N)
// SC : O(N)
// ########################
vector<int> rearrangeQueue(queue<int> &q)
{
    queue<int> newQ;
    vector<int> ans;
    int qSize = q.size();
    for (int i = 0; i < qSize / 2; i++)
    {
        int num = q.front();
        newQ.push(num);
        q.pop();
    }

    while (!newQ.empty())
    {
        ans.push_back(newQ.front());
        newQ.pop();
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}


// ########################
// Approach - 3 : Using stack, AC
// Babbar Approach
// TC : O(N)
// SC : O(N)
// ########################
vector<int> rearrangeQueue(queue<int> &q)
{
    stack<int> st;
    int n = q.size();
    vector<int> ans;

    // push 1st half of queue elements into stack
    for (int i = 0; i < n / 2; i++)
    {
        int num = q.front();
        st.push(num);
        q.pop();
    }

    // push stack elements back to queue
    while (!st.empty())
    {
        int num = st.top();
        q.push(num);
        st.pop();
    }

    // move 1st half of queue elements to the back
    for (int i = 0; i < n / 2; i++)
    {
        int num = q.front();
        q.push(num);
        q.pop();
    }

    // push 1st half of queue elements into stack
    for (int i = 0; i < n / 2; i++)
    {
        int num = q.front();
        st.push(num);
        q.pop();
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        ans.push_back(q.front());
        q.pop();
        st.pop();
    }

    return ans;
}

int main()
{

    return 0;
}