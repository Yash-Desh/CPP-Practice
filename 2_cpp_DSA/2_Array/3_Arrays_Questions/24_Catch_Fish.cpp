// Author : Yash Deshpande
// Date : 20-07-2023
// Tutor : Love Babbar Weekly Contest - 3

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// TC : O(N^2)
// TLE
int minimumNet(int n, int k, vector<bool> fish)
{
    // Write your code here.
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            if (fish[j])
            {
                sum++;
            }
            if (sum >= k && j - i + 1 < ans)
            {
                ans = j - i + 1;
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

// Better Approach : My Approach
// TC : O(N * LogN)
// AC
bool isPossible(int n, int k, vector<bool> &fish, int windowSize)
{
    int sum = 0;

    // creating the first window
    int i = 0;
    for (; i < windowSize; i++)
    {
        if (fish[i])
        {
            sum++;
        }
    }
    if (sum >= k)
    {
        return true;
    }

    for (; i < n; i++)
    {
        // Add the first element of the new window
        if (fish[i])
        {
            sum++;
        }

        // remove the last of the previous window
        int removeIndex = i - windowSize;
        if (fish[removeIndex])
        {
            sum--;
        }

        if (sum >= k)
        {
            return true;
        }
    }
    return false;
}

int minimumNet(int n, int k, vector<bool> fish)
{
    // Write your code here.

    // Binary Search Approach
    int low, mid, high;
    low = 1;
    high = n;
    int ans = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (isPossible(n, k, fish, mid))
        {
            ans = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return ans;
}



// Best Approach
/*
    Time Complexity: O(N)
    Space Complexity: O(1)
    where 'N' is the number of segments.
*/

int minimumNet(int n, int k, vector<bool> fish)
{
    // Assign large value to INF.
    const int INF = 1e9;

    int ans = INF, r = -1, count = 0;
    for (int l = 0; l < n; ++l)
    {
        // If r < l-1, make r = l-1.
        r = max(r, l - 1);

        while (r < n - 1 && count < k)
        {
            r++;
            // If fish present at r.
            if (fish[r])
                count++;
        }

        // If count of fish == k, r-l+1 is a viable answer.
        if (count == k)
            ans = min(ans, r - l + 1);

        // If fish present at l.
        if (fish[l])
            count--;
    }

    // If ans is INF, that means no fish were found.
    if (ans == INF)
        ans = -1;
    return ans;
}

int main()
{

    return 0;
}