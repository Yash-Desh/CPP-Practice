// Author : Yash Deshpande
// Date : 14-10-2022
// Topic : Strings
// Tutor : 450 DSA

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<char, int> value = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToDecimal(string &str)
    {
        // code here
        int ans = 0;
        for (int i = 0; i < str.size() - 1; i++)
        {
            if (value[str[i]] >= value[str[i + 1]])
                ans = ans + value[str[i]];
            else
                ans -= value[str[i]];
        }
        ans += value[str[str.size() - 1]];
        return ans;
    }
};

int main()
{

    return 0;
}