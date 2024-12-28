// Author : Yash Deshpande
// Date : 16-08-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach - 1 : Brute Force
// WA
//
class NStack
{
public:
    int *stack;
    int *pointer;
    int N, S;
    // Initialize your data structure.
    NStack(int N, int S)
    {
        this->N = N;
        this->S = S;
        // Write your code here.
        stack = new int[S];
        pointer = new int[N];
        int start = -1;
        for (int i = 0; i < N; i++)
        {
            pointer[i] = start;
            start += (S / N);
        }
    }

    // Pushes 'X' into the Mth stack.
    // Returns true if it gets pushed
    // into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if (pointer[m - 1] < (m * (S / N) - 1))
        {
            pointer[m - 1]++;
            stack[pointer[m - 1]] = x;
            return true;
        }
        else
            return false;
    }

    // Pops top element from Mth Stack.
    // Returns -1 if the stack is empty,
    // otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if (pointer[m - 1] > ((m - 1) * (S / N) - 1))
        {
            int value = stack[pointer[m - 1]];
            pointer[m - 1]++;
            return value;
        }

        else
            return -1;
    }
};

// Approach - 2 : Optimal Approach
// Babbar Approach
// AC
// Space Optimized Approach
// TC : O(1), 
// SC : O(S*N)
class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freeSpot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize top
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // Initialize next
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // change the last value in next to -1
        next[s - 1] = -1;

        // Initialize freespot to the position of next
        // free spot
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack.
    // Returns true if it gets pushed into the stack,
    // and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.

        // check for stack overflow
        if (freeSpot == -1)
            return false;

        // find index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // enter into stack
        arr[index] = x;

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack.
    // Returns -1 if the stack is empty,
    // otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.

        // check underflow condition
        if (top[m - 1] == -1)
            return -1;

        // find index
        int index = top[m - 1];

        // update top
        top[m - 1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};

int main()
{

    return 0;
}