// Author : Yash Deshpande 
// Date : 15-08-2022
// Tutor : Striver

// Q. Check if a given string is palindrome or not "RECURSIVELY"

// NOTE : time = O(n/2)   .... n = number of elements in the string
//        space = O(n/2)  

#include <bits/stdc++.h>
using namespace std;


// // single pointer recursive function to check palindrome
// bool checkPalindrome (string st, int i )         // n = length of the string
// {
//     if( i >= st.length()/2)
//         return true;
//     if(st[i] != st[st.length()-1-i])
//         return false;
//     return checkPalindrome(st,i+1);
// }


// 2-Pointer Recursive Approach
bool checkPalindrome (string st, int i, int j)
{
    if(i >= j)
        return true;

    if(st[i] != st[j])
        return false;

    return checkPalindrome(st, i+1, j-1);
}

int main()
{
    string st = "madam";
    cout<<checkPalindrome(st,0, st.size()-1);
    return 0;
}