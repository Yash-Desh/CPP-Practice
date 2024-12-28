// Author : Yash Deshpande
// Date : 1-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach-1 : Brute Force , AC
// TC : O(N)
// SC : O(N)

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   vector <int> copy;
    while(!inputStack.empty())
    {
        copy.push_back(inputStack.top());
        inputStack.pop();
    }
    
    int mid = N/2;
    for(int i=copy.size()-1; i>=0; i--)
    {
        if(i == mid)
            continue;
        inputStack.push(copy[i]);
    }
}


// Approach-2 : Recursion
// TC : O(N)
// SC : O(N)

void solve (stack<int> &inputStack, int N, int count)
{
    // Base Case
    if(count == N/2)
    {
        inputStack.pop();
        return;
    }
    int stackTop = inputStack.top();
    inputStack.pop();
    solve(inputStack, N, count+1);
    inputStack.push(stackTop);
}
void deleteMiddle(stack<int>&inputStack, int N){
   // Write your code here
   int count = 0;
    solve(inputStack, N, count);
}

int main()
{
    
    return 0;
}