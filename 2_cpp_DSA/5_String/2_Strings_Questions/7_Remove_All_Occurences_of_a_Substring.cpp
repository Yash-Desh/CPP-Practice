// Author : Yash Deshpande
// Date : 08-09-2022
// Topic : Strings
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// TC : O(N*M)  ... N = length of s
//              ... M = length of part
// SC : O(1) 
string removeOccurrences(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    // I personally logically like the below condition 
    // However the above condition is also able to pass all test cases
    // while(s.size() >= part.size() && s.find(part) != string::npos)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{

    return 0;
}