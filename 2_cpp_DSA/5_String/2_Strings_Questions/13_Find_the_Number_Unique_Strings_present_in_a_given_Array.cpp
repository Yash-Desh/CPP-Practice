// Author : Yash Deshpande
// Date : 10-09-2022
// Topic : Strings
// Tutor : Apni Kaksha

#include <bits/stdc++.h>
using namespace std;

// // Brute Force
// // TC = O(n*m*logn)
// int countUniqueStrings(vector<string> &str)
// {
//     // sort
//     sort(str.begin(), str.end());
//     int cnt = 0;
//     int n = str.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0 || str[i] != str[i - 1])
//         {
//             cnt++;
//         }
//     }
//     return cnt;
// }

// Better Approach : Using Hashing
// TC = O(nm + nlong(n))

// Utility function to calculate the hash of each string
long long calculateHash(string s)
{
    // Calculate powers of the hash function
    int base = 31; // could be any number greater than 27
    int n = 1e5 + 3, m = 1e9 + 7;
    vector<long long> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++)
    {
        power[i] = (power[i - 1] * base) % m;
    }       

    int hash = 0;
    for(int i=0; i<s.size(); i++)
    {
        hash = (hash +(s[i]-'a'+1) * power[i])%m;
    }
    return hash;
}

int countUniqueStrings(vector <string> str)
{
    // create a hashmap to store hashes of all strings
    vector<long long> h;
    for (string word : str)
    {
        h.push_back(calculateHash(word));
    }

    // sort the hashes
    sort(h.begin(), h.end());

    // calculate the distinct hashes
    int cnt = 0;
    for (int i = 0; i < h.size(); i++)
    {
        if (i == 0 || h[i] != h[i - 1])
            cnt++;
    }
    return cnt;
}

int main()
{
    vector <string> str = {"aa", "ab", "cc", "aa", "b", "aa", "dc"};
    cout << countUniqueStrings(str) << endl;
    return 0;
}