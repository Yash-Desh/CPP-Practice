// Author : Yash Deshpande
// Date : 09-09-2022
// Topic : Strings
// Tutor : 450 DSA

#include <bits/stdc++.h>
using namespace std;

// Recursive Approach  : AC
// TC = O(N * 2^N)
void makeSubsequence(int pos, string &temp, string str, vector<string> &ans)
{
    ans.push_back(temp);
    for (int i = pos; i < str.size(); i++)
    {
        temp.push_back(str[i]);
        makeSubsequence(i + 1, temp, str, ans);
        temp.pop_back();
    }
}

vector<string> subsequences(string str)
{

    // Write your code here
    vector<string> ans;
    int n = str.size();
    string temp = "";
    makeSubsequence(0, temp, str, ans);
    // Remove the empty subsequence if required
    ans.erase(ans.begin());

    // return the answer vector
    return ans;
}



// Power Set Method
vector<string> AllPossibleStrings(string s)
{
    // Code here
    int n = s.size();
    vector<string> ans;
    for (int i = 1; i < (1 << n); i++)
    {
        string temp = "";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp += s[j];
            }
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}