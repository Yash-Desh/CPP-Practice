// Author : Yash Deshpande
// Date : 1-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Babbar Approach
// TC : :O(N^2)
// SC : O(N)

void insertAtBottom (stack <int> &stack, int data)
{
    // base Case
    if(stack.empty())
    {
        stack.push(data);
        return;
    }
    int val = stack.top();
    stack.pop();
    insertAtBottom(stack, data);
    stack.push(val);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    // base case
    if(stack.empty())
        return;
    
    int data = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom (stack, data);
        
}

int main()
{
    
    return 0;
}