// Author : Yash Deshpande
// Date   : 04-09-2025
// Tutor  : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution_Sorting{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        // Sort the array
        sort(arr, arr+r+1);

        return arr[k-1];
    }
};

class Solution_Priority_Queue {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        // Create a max heap for the 1st k elements in the array
        priority_queue<int> pq;
        for(int i=0; i<k; i++) {
            pq.push(arr[i]);
        }
        
        // For the remaining n-k elements, if less than the root 
        // delete the root & insert into the max heap,  
        for(int i=k; i<arr.size(); i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};

int main() {
    return 0;
}