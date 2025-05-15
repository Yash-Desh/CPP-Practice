// Author : Yash Deshpande
// Date : 26-08-2022
// Tutor : Love Babbar
// Platform : Coding Ninjas

#include <bits/stdc++.h>
using namespace std;


// Approach - 1 : Brute Force
// AC
// TC : O(N)
int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    for(int i=0; i<n; i++)
    {
        if(arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

// love babbar solution
class Solution {
    int find_pivot(vector<int>& nums)
    {
        int l = 0;
        int h = nums.size()-1;

        while(l < h)
        {
            int mid = l + (h-l)/2;

            if(nums[mid] > nums[nums.size()-1])
            {
                l = mid+1;
            }
            else 
                h = mid;
        }
        return l;
    }

    int binary_search(vector<int>& nums, int low, int high, int target)
    {
        int l=low;
        int h=high;

        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
                h = mid-1;

            else 
                l = mid+1;
        }
        return -1;
    }


public:
    int search(vector<int>& nums, int target) {
        int pivot = find_pivot(nums);

        if(target >= nums[pivot] && target <= nums[nums.size()-1])
        {
            return binary_search(nums, pivot, nums.size()-1, target);
        }
        else 
            return binary_search(nums, 0, pivot-1, target);
    }
};



int main()
{
    
    return 0;
}