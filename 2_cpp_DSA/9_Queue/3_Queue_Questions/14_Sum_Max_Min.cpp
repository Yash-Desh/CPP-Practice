// Author : Yash Deshpande
// Date : 15-04-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// ########################
// Approach - 1 : Brute Force
// Babbar Approach
// TC : O(N*K)
// SC : O(1)
// ########################

// int solve (int *arr, int n, int k)
// {
//     int sum = 0;
    
//     for(int i=0; i<n-k+1; i++)
//     {
//         int maxi = INT_MIN;
//         int mini = INT_MAX;
//         for(int j=i; j <i+k; j++)
//         {
//             maxi = max(maxi, arr[j]);
//             mini = min(mini, arr[j]);
//         }
//         sum += (maxi + mini);
//     }

//     return sum;
// }


// ########################
// Approach - 2 : Optimal Approach
// Babbar Approach
// TC : O(N)
// SC : O(K)
// ########################

int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}





int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout<<solve(arr, 7, k)<<endl<<endl;  
    cout<<"hello world"<<endl;

    return 0;
}