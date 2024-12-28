/*
Given n string & q querries .
In each querry you are given a string , 
print frequency of that string
*/


// Use unordered_map instead of map : Here order doesn't matter, so we save some time complexity

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;   // n = number of strings to input
    cin>>n;
    unordered_map<string , int> mp;   // key = string  , value = frequency
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        mp[s]++;   // add every string into the map
    }

    int q ;  // q = number of querries
    cin>>q;
    for(int j=0; j<q; j++)
    {
        string querry;
        cin>>querry;
        cout<<mp[querry]<<endl;
    }
    
    return 0;
}