// Author : Yash Deshpande
// Date : 16-04-2024
// Tutor : Striver

#include <bits/stdc++.h>
using namespace std;

// ###############################################################
// Approach - 1 : Push operation is costly
// Striver Approach
// AC
// TC : O(N)  -> only for push operation
// SC : O(N)
// ###############################################################

class Queue1
{
    stack<int> input, output;

public:
    // Push elements in queue
    // TC : O(N)
    void enqueue(int x)
    {

        // Push all elements of input to output
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        // push new element into input
        input.push(x);

        // push all elements back from output to input
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    // Pop the element from the Queue
    // TC : O(1)
    int dequeue()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }

        int num = input.top();
        input.pop();
        return num;
    }

    // Return the Topmost element from the Queue
    // TC : O(1)
    int Top()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        return input.top();
    }

    // Return the size of the Queue
    // TC : O(1)
    int size()
    {
        return input.size();
    }
};

// ###############################################################
// Approach - 2 : Pop operation is costly
// Striver Approach
// AC
// TC : O(1)  -> Amortized TC for top() / pop() operation
// SC : O(N)
// ###############################################################
class Queue2
{
    stack<int> input, output;

public:
    // Push element x to the back of queue.
    // TC : O(1)
    void enqueue(int x)
    {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element.
    // TC : O(1) -> Amortized
    int dequeue()
    {
        // if both stacks are empty
        if (output.empty() && input.empty())
        {
            return -1;
        }

        // if output is empty, move
        // elements from input
        if (output.empty() && !input.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        // return the top item from output
        int num = output.top();
        output.pop();
        return num;
    }

    // Get the front element.
    // TC : O(1) -> Amortized
    int top()
    {
        // if both stacks are empty
        if (output.empty() && input.empty())
        {
            return -1;
        }

        // if output is empty, move
        // elements from input
        if (output.empty() && !input.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        // return the top item from output
        return output.top();
    }

    int size()
    {
        return input.size() + output.size();
    }
};



int main()
{

    return 0;
}