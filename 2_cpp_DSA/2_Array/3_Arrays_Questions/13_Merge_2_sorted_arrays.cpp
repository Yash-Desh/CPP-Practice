// Author : Yash Deshpande
// Date : 01-07-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// TC : O[(m+n)*(log(m+n))]
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[i - m];
    }
    sort(nums1.begin(), nums1.end());
}

// Optimal Approach
// TC : O(m+n)
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int ptr1 = m - 1;
    int ptr2 = n - 1;
    int ansPtr = n + m - 1;

    while (ptr1 >= 0 && ptr2 >= 0)
    {
        if (nums1[ptr1] > nums2[ptr2])
        {
            nums1[ansPtr--] = nums1[ptr1--];
        }

        else
        {
            nums1[ansPtr--] = nums2[ptr2--];
        }
    }

    while (ptr1 >= 0)
    {
        nums1[ansPtr--] = nums1[ptr1--];
    }

    while (ptr2 >= 0)
    {
        nums1[ansPtr--] = nums2[ptr2--];
    }
}

int main()
{

    return 0;
}