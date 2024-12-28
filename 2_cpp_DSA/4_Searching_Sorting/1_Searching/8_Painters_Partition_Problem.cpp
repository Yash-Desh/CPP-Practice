// Author : Yash Deshpande
// Date : 2-09-2022
// Tutor : Love Babbar
// Platform : Coding Ninjas

#include <bits/stdc++.h>
using namespace std;


bool isPossible(int mid, vector<int> &boards, int n, int k)
{
    int painters = 1;
    int boardsCnt = 0;
    for(int i=0; i<n; i++)
    {
        if(boardsCnt + boards[i] <= mid)
        {
            boardsCnt += boards[i];
        }
        else
        {
            painters++;
            if(painters > k || boards[i] > mid)
            {
                return 0;
            }
            boardsCnt = boards[i];
        }
    }
    return 1;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    // Binary Search
    int n = boards.size();
    int s=0;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += boards[i];
    }
    int e = sum;
    int ans=-1;
    
    while(s <= e)
    {
        int mid = s +(e-s)/2;
        if(isPossible(mid, boards, n,k))
        {
            ans = mid;
            e = mid-1;
        }
        else 
        {
            s = mid+1;
        }
    }
    return ans;
}


int main()
{
    
    return 0;
}