// Author : Yash Deshpande
// Date : 06-09-2022
// Topic : Strings
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// without using stack
string reverseWords(string s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            int j = i + 1;
            while (j != s.size() && s[j] != ' ')
            {
                j++;
            }
            string sub = s.substr(i, j - i);
            sub.append(ans);
            ans = sub;
            string space = " ";
            space.append(ans);
            ans = space;
            i = j;
        }
    }
    ans.erase(0, 1);
    return ans;
}

// Using stack
bool isValid(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 1;
    else
        return 0;
}

string reverseWords(string s)
{
    int n = s.size();
    stack<string> st;
    for (int i = 0; i < n; i++)
    {
        if (isValid(s[i]))
        {
            int j = i + 1;
            while (j != n && s[j] != ' ')
            {
                j++;
            }
            st.push(s.substr(i, j - i));
            i = j;
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans = ans + st.top() + " ";
        st.pop();
    }
    ans.pop_back();
    return ans;
}

int main()
{

    return 0;
}