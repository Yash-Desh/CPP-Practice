// Author : Yash Deshpande
// Date : 2-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Approach 1 : Using Stack
// TC : O(N)
// SC : O(N)

// Approach-1 : Method-1
// Method by Love Babbar
int findMinimumCost(string str)
{
    // Write your code here

    // Expressions of odd lengths
    // cannot be balanced
    if (str.size() & 1)
        return -1;

    stack<char> st;
    int c1 = 0, c2 = 0;

    // for loop to create stack of invalid brackets
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    while (!st.empty())
    {
        if (st.top() == '{')
            c1++;
        else
            c2++;
        st.pop();
    }
    // Why +1 before dividing by 2 ?
    // L55 Love Babbar logic explained
    return (c1 + 1) / 2 + (c2 + 1) / 2;
}



// Approach-1 , Method-2
// TC : O(N)
// SC : O(N)
int countRev(string s)
{
    // your code here

    // corner case
    // Expressions of odd lengths
    // cannot be balanced
    if (s.size() & 1)
        return -1;

    else
    {
        // maintain a count of all unbalanced
        // opening & closing brackets seperately

        int c1 = 0; // for opening brackets
        int c2 = 0; // for closing brackets
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{')
            {
                st.push('{');
                c1++;
            }
            else
            {
                if (st.empty())
                    c2++;

                else
                {
                    st.pop();
                    c1--;
                }
            }
        }
        // Why take ceil ? 
        // L55 Love Babbar logic explained
        c2 = ceil((float)c2 / 2);
        c1 = ceil((float)c1 / 2);
        return c1 + c2;
    }
}


// Approach 2 : Not using Stack
// TC : O(N)
// SC : O(1)
int findMinimumCost(string str) {
  // Write your code here

  // if length is odd
  if(str.length()&1)
    return -1;

  int left = 0, right = 0;
  for(int i=0; i<str.size(); i++)
  {
    char ch = str[i];
    if(ch == '{')
      left++;

    else
    {
      if(left == 0)
        right++;

      else
        left--;
    }
  }

  return ceil(float(left)/2) + ceil(float(right)/2);
}


int main()
{

    return 0;
}