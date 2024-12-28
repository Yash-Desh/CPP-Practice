// Author : Yash Deshpande
// Date : 26-08-2022
// Tutor : Love Babbar
// Platform : LeetCode

#include <bits/stdc++.h>
using namespace std;



// My Approach : Linear Traversal
//               Find the largest number in the array
// TC : O(n)
int peakIndexInMountainArray(vector<int> &arr)
{
    // brute force : using linear traversal

    int ans_index = -1;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            ans_index = i;
            break;
        }
    }
    return ans_index;
}


// Another Brute Force approach : 
// TC : O(N)
// Find the element of max value 




// Optimum Solution : Using binary search
// TC : O(logn)

int peakIndexInMountainArray(vector<int> &arr)
{
    int l = 0, h = arr.size() - 1;
    int mid;
    while (l < h)
    {
        mid = (l + h) / 2;

        // case - 1 
        if (arr[mid] < arr[mid + 1])
        {
            l = mid + 1;
        }

        // case - 2 (arr[mid] > arr[mid + 1])
        else
        {
            h = mid;
        }
    }
    // low / high any of the 2 pointers can be returned
    // the loop breaks only when both of them point at the 
    // same index
    return l;
}




// Binary Search : Recursive Approach
int solve(vector<int> &arr, int l, int h)
{
    // Base Case
    if (l >= h)
        return l;

    int mid = l + (h - l) / 2;
    if (arr[mid] < arr[mid + 1])
        return solve(arr, mid + 1, h);

    else
        return solve(arr, l, mid);
}
int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int l = 0, h = n - 1;
    int ans = solve(arr, l, h);
    return ans;
}

int main()
{

    return 0;
}