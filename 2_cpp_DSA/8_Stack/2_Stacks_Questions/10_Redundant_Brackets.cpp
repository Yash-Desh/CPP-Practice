// Author : Yash Deshpande
// Date : 1-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Babbar Approach
// TC : O(N)
// SC : O(N)

bool findRedundantBrackets(string &s)
{
    // Each pair of brackets '()' should have atleast one operator to consume
    // or in other words atleast one operator between '()' a pair of brackets
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // ch ya toh ')' hai or lowercase letter

            if (ch == ')')
            // Note : if the string encounters a ')' i.e a closing bracket then it
            // is certain that the string also had atleast 1 '(' i.e opening bracket
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}

int main()
{

    return 0;
}