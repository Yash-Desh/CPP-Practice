// Author : Yash Deshpande
// Date : 11-09-2022
// Tutor : Abdul Bari , Love Babbar

#include <iostream>
using namespace std;

// Recursive Approach

// 1-Pointer
void solve(string &str, int i)
{
    if(i >= str.size()/2)
        return;
    swap(str[i], str[str.size()-i-1]);
    solve(str, i+1);
}

// 2-Pointer
void solve(string &str, int i, int j)
{
    if(i >= j )
        return;
    swap(str[i], str[j]);
    solve(str, i+1, j-1);
}

int main()
{
    
    return 0;
}