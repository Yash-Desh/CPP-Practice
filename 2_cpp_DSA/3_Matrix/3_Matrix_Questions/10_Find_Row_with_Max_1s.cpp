// Author : Yash Deshpande
// Date : 05-09-2022
// Website : LeetCode
// Tutor : Striver
// Topic : Matrix

#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxCnt = 0;
	    int index = -1;
	    for(int i=0; i<n; i++)
	    {
	        int currentCnt =0;
	        for(int j=0; j < m; j++)
	        {
	            if(arr[i][j] == 1)
	                currentCnt++;
	        }
	        if(currentCnt > maxCnt)
	        {
	            index = i;
	            maxCnt = currentCnt;
	        }
	    }
	    return index;
	}


// Better Approach : Binary Search
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int max1s = 0;
	    int rowIndex = -1;
	    
	    // loop to run over every row
	    for(int i=0; i<n; i++)
	    {
	        int low = 0;
	        int high = m-1;
	        int currentRow1s = 0;
	        
	        while(low <= high)
	        {
	            int mid = (low + high)/2;
	            if(arr[i][mid] == 1)
	            {
	                high = mid-1;
	                
	                // calculate current number of 1s
	                currentRow1s = m-mid;
	            }
	            else
	            {
	                low = mid+1;
	            }
	        }
	        // compare
	        if(currentRow1s > max1s)
	        {
	            max1s = currentRow1s;
	            rowIndex = i;
	        }
	    }
	    return rowIndex;
	}


// Best Approach
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int indexOf1 = m-1;
	    int rowIndex = -1; 
	    for(int i=0; i<n; i++)
	    {
	        while (arr[i][indexOf1] == 1)
	        {
	            rowIndex=i;
	            indexOf1--;
	        }
	    }
	    return rowIndex;
	}

int main()
{
    
    return 0;
}