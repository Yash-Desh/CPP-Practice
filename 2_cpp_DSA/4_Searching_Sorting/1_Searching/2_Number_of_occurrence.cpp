// Author : Yash Deshpande
// Date : 26-08-2022
// Tutor : Love Babbar
// Platform : GFG

#include <bits/stdc++.h>
using namespace std;

// My Approach : Using Linear Search
// TC : O(n)

int count(int arr[], int n, int x)
{
    // code here
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cnt++;
        }
    }
    return cnt;
}

// Best Approach : Using Binary Search
// TC : O(logn)

// function to find the first occurence of k
// function to find the left-most occurence of k
int firstOcc(int arr[], int n, int k)
{
    int l = 0;
    int h = n - 1;
    int mid, ans = -1;
    while (l <= h)
    {
        mid = (l + h) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            h = mid - 1;
        }

        else if (arr[mid] < k)
        {
            l = mid + 1;
        }

        else if (arr[mid] > k)
        {
            h = mid - 1;
        }
    }
    return ans;
}

// function to find the last occurence of k
// function to find the right-most occurence of k
int lastOcc(int arr[], int n, int k)
{
    int l = 0;
    int h = n - 1;
    int mid, ans = -1;
    while (l <= h)
    {
        mid = (l + h) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            l = mid + 1;
        }

        else if (arr[mid] < k)
        {
            l = mid + 1;
        }

        else if (arr[mid] > k)
        {
            h = mid - 1;
        }
    }
    return ans;
}

int count(int arr[], int n, int x)
{
    // code here
    if(firstOcc(arr,n,x)==-1)
        return 0;
    int cnt=lastOcc(arr,n,x)-firstOcc(arr,n,x)+1;
    return cnt;
}

int main()
{
    int a[] = {1, 2, 2, 2, 4};
    cout << firstOcc(a, 5, 2) << endl;
    cout << lastOcc(a, 5, 2) << endl;
    return 0;
}