// Author : Yash Deshpande
// Date : 05-09-2022
// Website : LeetCode
// Tutor : Striver
// Topic : Matrix

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// Brute Force
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  multiset <int> sorter;
  for(int i=0; i<n; i++)
  {
      for(int j=0; j<n; j++)
      {
          sorter.insert(mat[i][j]);
      }
  }
  
  multiset <int> :: iterator it = sorter.begin();
  for(int i=0; i<k-1; i++ )
  {
      it++;
  }
  return *(it);
}

int main()
{

    
    return 0;
}