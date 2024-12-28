// Author : Yash Deshpande
// Date : 08-08-2022
// Tutor : Love Babbar

// Qs Link : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa2MyYmxaQW5NbFQ0cDQyZlJSeUFHOUtEV2pMQXxBQ3Jtc0tsaWt6cGNxR1I3RVFYaDR6OHR6cU90RFVyNC1fUEJIbnNtWk1CeC1mTU9jMF9qYXdKLUNha3ZUNUdVWkRmcE9EX3g2QWo4S2tjY0I1WVB6cHdXRHVreFdka0Z0V2Y2UDJfV3ZRY2ROV0xUOUpGRVZxRQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fmaximum-occuring-character-1587115620%2F1&v=Wdjr6uoZ0e0

// NOTE : Solution here is not the exact solution

#include <bits/stdc++.h>
using namespace std;

char getMaxOccChar (string s)
{
    // create hash table storing the occurence count of each alphabet
    int hash[26] ={0};
    for(int i=0; i<s.length(); i++)
    {
        // for lowercase letters
        if(s[i]>='a' && s[i]<='z')
        {
            hash[s[i]-'a']++;
        }
        // for uppercase letters 
        else
        {
           hash[s[i]-'A']++; 
        }
    }

    // find the char to occur max times 
    int max = -1, ans = -1;
    for(int i =0; i<26; i++)
    {
        if(hash[i] > max)
        {
            max = hash[i];
            ans = i;
        }
    }

    return 'a' + ans;
}

int main()
{
    string st;
    cout<<"Enter string : ";
    cin>>st;

    cout<<getMaxOccChar (st)<<endl;
    return 0;
}