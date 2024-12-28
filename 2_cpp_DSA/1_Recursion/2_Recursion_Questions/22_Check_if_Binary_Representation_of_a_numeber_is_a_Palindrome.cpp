// Author : Yash Deshpande
// Date : 11-09-2022
// Tutor :  Love Babbar

#include <bits/stdc++.h>
using namespace std;

void intToBin(long long N, vector <int> &binNum)
{
    while(N)
    {
        int bit = N&1;
        binNum.push_back(bit);
        N>>1;
    }
    reverse(binNum.begin(), binNum.end());
}


bool solve (vector <int> binNum, int i)
{
    if(i >= binNum.size()/2)
        return true;
    if(binNum[i] != binNum[binNum.size()-1-i])
        return false;
    return solve(binNum , i+1);
}

bool checkPalindrome(long long N)
{
	// Write your code here.
    vector <int> binNum;
    intToBin(N, binNum);
    return solve(binNum, 0);
}


int main()
{
    long long n  = 15;
    vector <int> ans; 
    intToBin(n , ans);
    for(int i: ans)
        cout<<i<<" ";
    return 0;
}