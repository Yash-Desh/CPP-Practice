

/*
Given n strings print unique strings 
in lexicographical order along with 
their frequency
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;   // n = number of strings to input
    cin>>n;
    map<string , int> mp;   // key = string  , value = frequency
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        mp[s]++;   // add every string into the map
    }

    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}