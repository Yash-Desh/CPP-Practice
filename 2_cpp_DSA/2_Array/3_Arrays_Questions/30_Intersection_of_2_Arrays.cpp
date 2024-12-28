// Author : Yash Deshpande
// Date : 27-07-2023
// Tutor : 450 DSA

// ########################################
// For Unsorted arrays
// All array elements are not distinct
// ########################################

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// My Approach : Brute Force
// Abdul Bari Method
// TLE
// TC : O(n*m)
// SC : O(1)

int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    // Your code goes here

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
                count++;
        }
    }
    return count;
}

// Approach - 2 : Sort if the array is unsorted
// TC : O(nlogn + mlogm + max(n, m))
// SC :O(1)

// Function to return the count of the number of elements in
// the intersection of two arrays.
int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    // Your code goes here

    sort(a, a + n);
    sort(b, b + m);

    int count = 0;

    int i = 0, j = 0;
    int temp = -1;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            if (a[i] != temp)
            {
                count++;
                temp = a[i];
                i++;
                j++;
            }
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return count;
}

// Optimal Approach : Using unordered set
// TC : O(n+m)
// SC : O(n)
int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    // Your code goes here

    int count = 0;
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
    {
        us.insert(a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        if (us.find(b[i]) != us.end())
        {
            count++;
            us.erase(b[i]);
        }
    }

    return count;
}

int main()
{

    return 0;
}