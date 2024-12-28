// Author : Yash Deshpande
// Data : 6-8-2022
// Tutor : Luv , Striver

/*

Given N strings & Q querries
In each querry you are given a string 
print yes if the string is present & 
print no if not present

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;      // number of strings to input
    cin>>N;

    unordered_set <string> s;
    while(N--)
    {
        string str;
        cin>>str;
        s.insert(str);
    }

    int Q;      // number of querries
    cin>>Q;

    for(int i=0; i<Q; i++)
    {
        string q;
        cin>>q;
        if(s.find(q) != s.end())
        {
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}