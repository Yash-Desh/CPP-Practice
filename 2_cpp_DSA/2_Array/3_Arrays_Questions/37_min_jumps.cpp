// Author : Yash Deshpande
// Date : 04-08-2023
// Topic : Arrays
// Tutor : 450 DSA

#include <bits/stdc++.h>
using namespace std;

// My Approach : AC
// TC : O(N^2)
// SC : O(1)

// Function to return minimum number of jumps to end of array

int minJumps(int arr[], int n)
{
    // Your code here
    int pos = 0;
    int jumps = 0;

    while (pos < n - 1)
    {
        if (arr[pos] == 0)
            return -1;
        if (arr[pos] >= n - 1 - pos)
        {
            jumps++;
            return jumps;
        }
        int next_pos = findMax(arr, pos + 1, pos + arr[pos] > n - 1 ? n - 1 : (pos + arr[pos]));
        pos = next_pos;
        jumps++;
    }
    return jumps;
}

// function to return the index of  value maximum
int findMax(int arr[], int i, int j)
{
    int max = INT_MIN;
    int max_ind;
    for (int k = i; k <= j; k++)
    {
        if ((arr[k] + k) > max)
        {
            max = arr[k] + k;
            max_ind = k;
        }
    }
    return max_ind;
}

// Approach : Code Library
// It uses similar concept to the above approach
// However this is more efficient
// TC : O(N)
// SC : O(1)
int minJumps(int arr[], int n)
{
    // Your code here

    int maxReach = arr[0];
    int step = arr[0];
    int jumps = 1;

    // if array has only 1 value
    if (n == 1)
        return 0;

    // if value of 1st integer in array = 0
    else if (arr[0] == 0)
        return -1;

    else
    {
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return jumps;
            }

            maxReach = max(maxReach, arr[i] + i);
            step--;

            if (step == 0)
            {
                jumps++;
                if (i >= maxReach)
                {
                    return -1;
                }

                step = maxReach - i;
            }
        }
    }
}

//{ Driver Code Starts.

int main()
{

    return 0;
}

// } Driver Code Ends