// Author : Yash Deshpande
// Data : 6-8-2022
// Tutor : Luv , Striver

/*

Given N strings , print unique strings
in lexicographical order
N <= 10^5
|s| <= 10000

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;    // number of strings 
    cin>>N;

    // inserting all the input strings into a map
    set <string> s;
    while(N--)
    {
        string st;
        cin>>st;
        s.insert(st);
    }

    for(string val : s)
    {
        cout<<val<<" ";
    }
    return 0;
}