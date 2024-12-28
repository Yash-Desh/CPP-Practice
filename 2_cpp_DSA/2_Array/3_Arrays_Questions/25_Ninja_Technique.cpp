// Author : Yash Deshpande
// Date : 25-07-2023
// Tutor : Love Babbar Weekly Contest - 3

#include <bits/stdc++.h>
using namespace std;


// TC : O(N * logN)
// SC : O(N)

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int ninjaTechnique(int n, vector<vector<int>> &a)
{
    // Write your code here.

    vector<pair<int, int>> store;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> temp;
        temp.first = min(a[i][0], a[i][1]);
        temp.second = max(a[i][0], a[i][1]);
        store.push_back(temp);
    }

    sort(store.begin(), store.end(), sortbysec);
    int prev = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (store[i].first > prev)
        {
            prev = store[i].second;
            ans++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}