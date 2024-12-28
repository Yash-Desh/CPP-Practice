// Author : Yash Deshpande
// Date : 18-07-2023
// Tutor : Striver , Love Babbar

#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, string path, vector<string> &ans, vector<vector<int>> &vis, vector<vector<int>> &m, int n)
{
    // Base CASE
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // Check for 3 conditions
    // 1. valid index wrt to matrix boundaries
    // 2. not visited previously
    // 3. has 1 in cell , so can be used as path

    // DOWN
    if (i + 1 < n && (vis[i + 1][j] != 1) && (m[i + 1][j] == 1))
    {
        vis[i][j] = 1;
        solve(i + 1, j, path + 'D', ans, vis, m, n);
        vis[i][j] = 0;
    }

    // LEFT
    if (j - 1 >= 0 && (vis[i][j - 1] != 1) && (m[i][j - 1] == 1))
    {
        vis[i][j] = 1;
        solve(i, j - 1, path + 'L', ans, vis, m, n);
        vis[i][j] = 0;
    }

    // RIGHT
    if (j + 1 < n && (vis[i][j + 1] != 1) && (m[i][j + 1] == 1))
    {
        vis[i][j] = 1;
        solve(i, j + 1, path + 'R', ans, vis, m, n);
        vis[i][j] = 0;
    }

    // UP
    if (i - 1 >= 0 && (vis[i - 1][j] != 1) && (m[i - 1][j] == 1))
    {
        vis[i][j] = 1;
        solve(i - 1, j, path + 'U', ans, vis, m, n);
        vis[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here

    // ans vector
    vector<string> ans;

    // list of visited cells
    vector<vector<int>> vis(n, vector<int>(n, 0));

    // call the function only if source is NOT equal to 0
    if (m[0][0] == 1)
    {
        solve(0, 0, "", ans, vis, m, n);
    }
    return ans;
}

int main()
{

    return 0;
}