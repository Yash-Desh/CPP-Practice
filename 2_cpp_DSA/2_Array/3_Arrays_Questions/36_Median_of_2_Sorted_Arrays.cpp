// Author : Yash Deshpande
// Date : 04-09-2022
// Website : LeetCode
// Tutor : Striver
// Topic : Arrays

#include <bits/stdc++.h>
using namespace std;


 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // ensure that Binary Search works on the smaller array
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2 , nums1);
        
        // store sizes of the 2 arrays
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        // initialize constraints of BS
        int l = 0;
        int h = size1;
        
        while(l <= h)
        {
            int mid = (l+h)/2;
            int cut1 = mid;
            int cut2 = (size1+size2+1)/2 - cut1;
            
            // why INT_MIN ? --> edge case
            int l1 = cut1 == 0  ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0  ? INT_MIN : nums2[cut2-1];
            
            // why INT_MAX ? --> edge case 
            int r1 = cut1 == size1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == size2 ? INT_MAX : nums2[cut2];
            
            
            if(l1 <= r2 && l2 <= r1)
            {
                if((size1+size2)&1)
                {
                    // odd number of elements
                    return double(max(l1,l2));
                }
                else 
                {
                    return double((max(l1,l2)+min(r1,r2))/2.000);
                }
            }
            
            else if(l1 > r2)
            {
                h = mid-1;
            }
            
            else if( l2 > r1)
            {
                l = mid +1 ;
            }
        }
        // This line will never run
        return -1;
    }

int main()
{
    

    return 0;
}