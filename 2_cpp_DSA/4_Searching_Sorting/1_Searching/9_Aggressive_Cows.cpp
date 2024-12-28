// Author : Yash Deshpande
// Date : 2-09-2022
// Tutor : Love Babbar
// Platform : Coding Ninjas

#include <bits/stdc++.h>
using namespace std;


bool isPossible(int mid, vector<int> &stalls, int k)
{
    int cowCnt = 1;
    int lastPosition =stalls[0];
    for(int i=0; i<stalls.size(); i++)
    {
        if(stalls[i]-lastPosition >= mid)
        {
            cowCnt++;
            if(cowCnt == k)
            {
                return true;
            }
            lastPosition = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int s=0;
    
    
    int ans =-1;
    int e = stalls[stalls.size()-1];
    while( s <= e)
    {
        int mid = s + (e-s)/2;
        if(isPossible(mid, stalls, k))
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return ans;
}


int main()
{
    
    return 0;
}