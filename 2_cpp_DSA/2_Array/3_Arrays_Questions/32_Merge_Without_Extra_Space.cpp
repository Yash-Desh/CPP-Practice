// Author : Yash Deshpande
// Date : 30-08-2022
// Website : GFG
// Topic : Arrays
// Tutor : Striver

// Q. Merge 2 sorted arrays without extra space

#include <bits/stdc++.h>
using namespace std;

// Approach-1: (Uses Extra Space)
// Copy elements of array 1 & array 2
// into a new larger array 3
// sort array 3
// Copy elements of array 3 sequentially 
// int array 1 & array 2
// TC : O(NlogN)
// SC : O(N)


// Approach-2 : (Uses Extra Space)
// Abdul Bari method
// TC : O(N)
// SC : O(N) 



// Approach-3 
// Since arrays are sorted
// Compare each element of array-1 with
// 1st element of array-2
// Swap them if required
// Sort array-2
// TC : O(N^2)
// SC : O(1)


// Approach-4
// Since arrays are sorted
// Compare each element of array-1 with
// 1st element of array-2
// Swap them if required
// Place the new element in array-2
// in sorted order by linear traversal
// TC : O(N^2)
// SC : O(1) 


// Approach-5 (Optimal)
// Striver didn't explain intuition only the algo


int main()
{
    
    return 0;
}