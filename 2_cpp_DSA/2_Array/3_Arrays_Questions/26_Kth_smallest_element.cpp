// Author : Yash Deshpande
// Date : 26-07-2023
// Tutor : 450 DSA

#include <bits/stdc++.h>
using namespace std;

// Method - 1 : Brute Force -> AC
// Using sorting
// TC : O(N * LogN)
// SC : O(1)

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k)
{
    // code here

    // Sort the array
    sort(arr, arr + r + 1);

    // return the kth smallest element
    return arr[k - 1];
}

// Method - 2 : Using priority queue as a min-heap
// TC : 
// SC : 
// TLE
int kthSmallest(int arr[], int l, int r, int k)
{
    // code here
    //  Using Priority Queue as min-heap
    priority_queue<int, vector<int>, greater<int>> gq;

    // enter all elements in the priority queue
    for (int i = 0; i <= r; i++)
    {
        gq.push(arr[i]);
    }

    // iterate through the priority queue until you get the kth element
    int i = 1;
    while (!gq.empty())
    {
        if (i == k)
            break;

        i++;
        gq.pop();
    }

    return gq.top();
}

int main()
{

    return 0;
}