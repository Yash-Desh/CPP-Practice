// Author : Yash Deshpande
// Date : 1-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Iterative Approach
// TC : O(N)
// SC : O(N)
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    int stackSize = myStack.size();
    int* arr = new int [stackSize];

    for(int i=0; i<stackSize; i++)
    {
        arr[i] = myStack.top();
        myStack.pop();
    }
    myStack.push(x);

    for(int i=stackSize-1; i>=0; i--)
    {
        myStack.push(arr[i]);
    }
    delete arr;
    return myStack;
}

// Recursive Approach
// TC : O(N)
// SC : O(N)
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    // base case
    if(myStack.empty())
    {
        myStack.push(x);
        return myStack;
    }
    int var = myStack.top();
    myStack.pop();
    pushAtBottom (myStack, x);
    myStack.push(var);
    return myStack;
}


int main()
{
    
    return 0;
}