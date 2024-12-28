// Author : Yash Deshpande
// Date : 1-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Method - 2 : By Luv
// TC : O(N)
// SC : O(N)
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    unordered_map<char, int> m = {{'(', 1}, {'{', 2}, {'[', 3}, {')', -1}, {'}', -2}, {']', -3}};
    for (int i = 0; i < expression.size(); i++)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty())
                return false;
            if ((m[st.top()] + m[ch] == 0))
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}


// Method-1 : By Love Babbar & Abdul Bari
// TC : O(N)
// SC : O(N)
bool isBalanced (string exp)
{
    stack<char> st;
    for(int i=0; i<exp.size(); i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            st.push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}' )
        {
            if(st.empty())
                return false;
            
            // ()
            char ch = st.top();
            if(exp[i] == ')' && ch == '(')
                st.pop();

            if(exp[i] == ']' && ch == '[')
                st.pop();

            if(exp[i] == '}' && ch == '{')
                st.pop();
            
        }
    }
    return st.empty();
}

int main()
{

    return 0;
}