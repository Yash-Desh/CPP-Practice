// Author : Yash Deshpande
// Date : 2-09-2022
// Tutor : Love Babbar
// Platform : SPOJ


#include <bits/stdc++.h>
using namespace std;

// TC = N*log(N)
// function to decide if chosen height
// will give the required quantity of wood

bool isPossible (int mid, int treeHeights[], int N, int M)
{
    int woodSum =0;

    for(int i=0; i<N; i++)
    {
        if((treeHeights[i] > mid))
        {
            
            woodSum += (treeHeights[i]-mid);
        }
    }
    if(woodSum >= M)
    {
        return true;
    }
    return false;
}

int maximizeHeight (int treeHeights[], int N, int M)
{
    int s=0; 
    int maxi =-1;
    for(int i=0; i<N; i++)
    {
        maxi = max(maxi, treeHeights[i]);
    }
    int e = maxi;
    int ans = -1;

    while(s <= e)
    {
        int mid = s + (e-s)/2;
        if(isPossible(mid, treeHeights, N, M))
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
    int N,M;
    
    cin>>N>>M;
    int treeHeights[N];

    for(int i=0; i<N; i++)
    {
        cin>>treeHeights[i];
    }
    cout<<maximizeHeight(treeHeights, N, M)<<endl;
    return 0;
}