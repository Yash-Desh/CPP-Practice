// Author : Yash Deshpande
// Date : 27-07-2023
// Tutor : 450 DSA

#include <bits/stdc++.h>
using namespace std;

// ########################################
// For Unsorted arrays
// All array elements are not distinct
// ########################################

// My Approach : Brute Force
// AC
// TC : o(n + m)  ... n & m are the sizes of the 2 arrays
// SC : O(n + m)
int doUnion(int a[], int n, int b[], int m)
{
    // code here
    // Using set data structure
    set<int> s;

    // Insert all elements of array 1 into set
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    // Insert all elements of array 2 into set
    for (int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }

    // return size of the created set
    return s.size();
}



// ########################################
// For Sorted arrays
// All array elements are not distinct
// ########################################

// Abdul Bari Approach + Modificati
// AC
// TC : O(n+m)
// SC : O(n+m)

// arr1,arr2 : the arrays
//  n, m: size of arrays
// Function to return a list containing the union of the two arrays.
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    // Your code here
    // return vector with correct order of elements
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            if (ans.empty() || arr1[i] != ans.back())
                ans.push_back(arr1[i]);
            i++;
            j++;
        }

        else if (arr1[i] < arr2[j])
        {
            if (ans.empty() || arr1[i] != ans.back())
                ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            if (ans.empty() || arr2[j] != ans.back())
                ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n)
    {
        if (ans.empty() || arr1[i] != ans.back())
            ans.push_back(arr1[i]);
        i++;
    }

    while (j < m)
    {
        if (ans.empty() || arr2[j] != ans.back())
            ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

int main()
{

    return 0;
}