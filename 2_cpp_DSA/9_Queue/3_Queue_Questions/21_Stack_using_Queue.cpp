// Author : Yash Deshpande
// Date : 16-04-2024
// Tutor : Striver

#include <bits/stdc++.h>
using namespace std;


// ###############################################################
// Approach - 1 : Push operation is costly, AC
// Striver Approach
// AC
// TC : O(N)  -> only for push operation
// SC : O(N)
// ###############################################################

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
    int top();
    int size();
};

// Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    // Your Code
    q2.push(x);

    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    swap(q1, q2);
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    // Your Code
    if (q1.empty())
        return -1;

    int num = q1.front();
    q1.pop();
    return num;
}

int QueueStack ::top()
{
    if (q1.empty())
        return -1;
    return q1.front();
}

int QueueStack ::size() { return q1.size(); }

// ###############################################################
// Approach - 2 : Pop operation is costly, AC
// My Approach
// AC
// TC : O(N)  -> only for pop operation
// SC : O(N)
// ###############################################################

class QueueUsingStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
    int top();
    int size();
};

// Function to push an element into stack using two queues.
void QueueUsingStack ::push(int x)
{
    // Your Code
    q1.push(x);
}

// Function to pop an element from stack using two queues.
int QueueUsingStack ::pop()
{
    // Your Code
    int num = 0;

    // If both q1 & q2 are empty
    if (q1.empty() && q2.empty())
        num = -1;

    while (!q1.empty())
    {
        num = q1.front();
        if (q1.size() != 1)
        {
            q2.push(q1.front());
        }
        q1.pop();
    }

    swap(q1, q2);
    return num;
}

// ###############################################################
// Approach - 3 : Single Queue used, AC
// Striver Approach
// TC : O(N)
// SC : O(N)
// ###############################################################


class MyStack
{
private:
    queue<int> q;

public:
    void push(int);
    int pop();
    int top();
};

void MyStack ::push(int x)
{
    q.push(x);

    // determine queue size
    int size = q.size();

    for (int i = 0; i < size - 1; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

int MyStack ::pop()
{
    if (q.empty())
        return -1;

    int num = q.front();
    q.pop();
    return num;
}

int MyStack ::top()
{
    if (q.empty())
        return -1;

    int num = q.front();
    return num;
}

int main()
{

    return 0;
}