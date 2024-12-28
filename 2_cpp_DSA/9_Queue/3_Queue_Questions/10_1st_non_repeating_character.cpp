// Author : Yash Deshpande
// Date : 12-04-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// ########################
// Approach - 1 : Babbar Approach
// Babbar Approach
// TC : O(N)
// SC : O(N)
// ########################
string FirstNonRepeating(string A)
{
    // Code here
    queue<char> q;
    string ans = "";
    unordered_map<char, int> count;

    for (int i = 0; i < A.size(); i++)
    {
        char ch = A[i];

        // Increase count
        count[ch]++;

        // Push into queue
        q.push(ch);

        while (!q.empty())
        {
            // Repeating character
            if (count[q.front()] > 1)
            {
                q.pop();
            }

            // Non-repeating character
            else
            {
                ans += q.front();
                break;
            }
        }
        if (q.empty())
        {
            ans += '#';
        }
    }
    return ans;
}

int main()
{

    return 0;
}