// Author : Yash Deshpande
// Date : 08-09-2022
// Topic : Strings
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Iterative Approach

// TC = O(N)
// SC = O(N)
string removeDuplicates(string s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        ans.push_back(s[i]);
        if (ans.size() >= 2)
        {
            if (ans[ans.size() - 1] == ans[ans.size() - 2])
            {
                ans.pop_back();
                ans.pop_back();
            }
        }
    }
    return ans;
}

// TC = O(N)
// SC = O(N)
string removeDuplicates(string s)
{
    // loop to check for duplicates
    string st = "";
    int i = 0;
    while (i < s.length())
    {

        if (i == 0)
        {
            st.push_back(s[i]);
        }
        else if (st.back() == s[i])
        {
            st.pop_back();
        }
        else
        {
            st.push_back(s[i]);
        }
        i++;
    }
    return st;
}
int main()
{

    return 0;
}