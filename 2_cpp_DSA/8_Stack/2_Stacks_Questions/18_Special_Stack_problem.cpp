// Author : Yash Deshpande
// Date : 19-08-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach - 1 : Brute Force
// Babbar Approach
// AC
// TC : O(1)
// SC : O(N)
class SpecialStack
{
private:
    stack<int> st;
    stack<int> minSt;

public:
    void push(int data)
    {
        // Implement the push() function.
        st.push(data);

        if (minSt.empty())
            minSt.push(data);

        else
            minSt.push(min(minSt.top(), data));
    }

    void pop()
    {
        // Implement the pop() function.
        st.pop();
        minSt.pop();
    }

    int top()
    {
        // Implement the top() function.
        return st.top();
    }

    int getMin()
    {
        // Implement the getMin() function.
        return minSt.top();
    }
};

// Approach - 2 : Optimal Approach
// Babbar Approach 
// AC
// TC : O(1)
// SC : O(1)
class SpecialStack
{
    stack<int> s;
    int mini;

public:
    void push(int data)
    {
        // Implement the push() function.
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }

        else
        {
            if (data < mini)
            {
                int value = 2 * data - mini;
                s.push(value);
                mini = data;
            }
            else
                s.push(data);
        }
    }

    void pop()
    {
        // Implement the pop() function.
        if (!s.empty())
        {
            int current = s.top();
            s.pop();

            if (current <= mini)
            {
                int value = 2 * mini - current;
                mini = value;
            }
        }
    }

    int top()
    {
        // Implement the top() function.
        if (s.empty())
            return -1;

        else
        {
            if (s.top() > mini)
                return s.top();

            else
                return mini;
        }
    }

    int getMin()
    {
        // Implement the getMin() function.
        return mini;
    }
};

int main()
{

    return 0;
}