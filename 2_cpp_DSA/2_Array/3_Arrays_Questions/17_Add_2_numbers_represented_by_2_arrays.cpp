// Author : Yash Deshpande
// Date : 06-09-2022
// Website : LeetCode
// Tutor : Love Babbar
// Topic : Arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
    
    vector <int> ans ;
    
    int i = n-1;
    int j = m-1;
    int carry = 0;
    while (i >=0 && j>=0)
    {
        int sum = a[i--] + b[j--] +carry;
        int digit = sum % 10;
        ans.push_back(digit);
        carry = sum /10;
    }
    while (i >= 0)
    {
        int sum = a[i--] + 0 +carry;
        int digit = sum % 10;
        ans.push_back(digit);
        carry = sum /10;
    }
    
    while (j >= 0)
    {
        int sum = b[j--] + 0 +carry;
        int digit = sum % 10;
        ans.push_back(digit);
        carry = sum /10;
    }
    if(carry)
    {
        ans.push_back(carry);
    }
    reverse (ans.begin(), ans.end());
    return ans;
}


int main()
{
    
    return 0;
}