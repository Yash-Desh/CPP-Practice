// Author : Yash Deshpande
// Date : 10-09-2022
// Topic : Strings
// Tutor : Apni Kaksha , 450 DSA

#include <bits/stdc++.h>
using namespace std;

// Calculating powers
int p =31;
int n = 1e5+3 , m = 1e9+7;
vector <long long> power(n);

int main()
{
    // Initialize the powers array
    power[0]=1;
    for(int i=1; i<n; i++)
    {
        power[i] = (power[i-1] * p)%m;
    }

    string s = "na";                // pattern
    string t = "apnacollgena";      // text
    int S = s.size();
    int T = t.size();


    // find the hash value of the pattern
    long long hashS = 0;
    for(int i=0; i<S; i++)
    {
        hashS = (hashS + (s[i]-'a'+1)*power[i])%m;
    }

    // calculate the prefix hashes of the text
    vector <long long> h(T+1, 0);
    for(int i=0; i<T; i++)
    {
        h[i+1] = (h[i] + (t[i]-'a'+1)*power[i])%m;
    }


    vector <int> ans;
    for(int i=0; i < T-S+1; i++)
    {
        long long currentHash = (h[i+S] - h[i] + m)%m;   // safegaurd against negative value after subtraction
        if(currentHash == (hashS * power[i])%m)
        {
            ans.push_back(i);
            cout<<i<<endl;
        }
    }


    return 0;
}