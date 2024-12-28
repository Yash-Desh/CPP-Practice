// Author : Yash Deshpande
// Date : 16-02-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// ########################
// Approach - 1 : Recursion
// Babbar Approach, TLE
// TC : O(N)
// SC : O(N)
// ########################
void solve (queue<int> &q)
{
    // base case
    if(q.empty())
        return;
        
    int value = q.front();
    q.pop();
    solve(q);
    q.push(value);
}

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here.
    solve(q);
    return q;
    
}


// #############################
// Approach - 2 : Stack
// Babbar Approach, AC
// TC : O(N)
// SC : O(N)
// Function to reverse the queue.
// #############################
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> st;
    
    // Put all the elements into stack
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    
    // Put all the elements back into the queue
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    
    return q;
}



int main()
{
    
    return 0;
}