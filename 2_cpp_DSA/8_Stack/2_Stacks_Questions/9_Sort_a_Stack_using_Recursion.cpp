// Author : Yash Deshpande
// Date : 1-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach : Recursive
// TC : O(N^2)
void insert(stack<int> &stack, int num)
{
    // base Case
    if (stack.empty())
    {
        stack.push(num);
        return;
    }

    if (stack.top() <= num)
    {
        stack.push(num);
        return;
    }

    /*
    NOTE : Combined case for the 2 upper if statements

    if(stack.empty() || (!stack.empty() && stack.top() <= num ))
    {
        stack.push(num);
        return;
    }
    
    */

    int data = stack.top();
    stack.pop();
    insert(stack, num);
    stack.push(data);
}

void sortStack(stack<int> &stack)
{
    // Write your code here
    // base Case
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack, num);
}

int main()
{

    return 0;
}