// Author : Yash Deshpande
// Date : 14-10-2022
// Topic : Strings
// Tutor : 450 DSA

#include <bits/stdc++.h>
using namespace std;

// // Approach -1 : Brute Force
// // TC :
// // SC :
// string longestCommonPrefix(vector<string> &strs)
// {
//     string ans = strs[0];
//     for (int i = 1; i < strs.size(); i++)
//     {
//         if (ans == "" || strs[i] == "")
//             return "";
//         string temp = ans;
//         ans = "";
//         int j = 0;
//         int cnt = min(temp.size(), strs[i].size());
//         while (temp[j] == strs[i][j] && j < cnt)
//         {
//             ans = ans + temp[j];
//             j++;
//         }
//     }
//     return ans;
// }

// Better Approach
string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";

    for (int i = 0; i < strs[0].size(); i++)
    {
        int j;
        for (j = 1; j < strs.size(); j++)
        {
            if (strs[0][i] != strs[j][i])
            {
                return ans;
            }
        }
        if (j == strs.size())
            ans = ans + strs[0][i];
    }
    return strs[0];
}

int main()
{
    string word = "hellow";
    cout<<word[0]<<endl;
    cout<<word[16]<<endl;
    return 0;
}