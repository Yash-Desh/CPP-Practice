// Author : Yash Deshpande
// Date : 06-09-2022
// Topic : Strings 
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// remove unwanted characters
     bool valid (char ch)
        {
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') ||(ch>='0' && ch<='9') )
            {
                return 1;
            }
            return 0;
        }
    
    // convert all alpha-numeric characters to lowercase
    char toLowerCase (char ch)
    {
        // if input character is lowercase, return the same unchanged
        if((ch >= 'a' && ch <= 'z') || (ch>='0' && ch<='9'))
        {
            return ch;
        }
        else // if input character is uppercase, return its lowercase version
        {
            return ch-'A'+'a';
        }
    }
    
    bool checkPalindrome1 (string arr)
{
    int s = 0;      // ptr to start of array
    int r = arr.length()-1;    // ptr to end of array
    while(s<r)
    {
        // if any character is not same then return 0
        if (arr[s] != arr[r])     
        {
            return 0;
        }
        s++;
        r--;
    }
    return 1;
}

bool checkPalindrome(string s)
{
    // Write your code here.
    // create a new string with only valid characters
        string temp = "";
        for(int j=0; j<s.length(); j++)
        {
            if(valid(s[j]))
               {
                   temp.push_back(s[j]);
               }
        }
               
        // convert all alphanumerals to lowercase 
        for(int j=0; j<temp.length(); j++)
        {
            temp[j] = toLowerCase(temp[j]);
        }
               
        return checkPalindrome1(temp);
        
        // NOTE : some of the important cases are 
        //        " " /  " , " / "a" .. etc
}

int main()
{
    
    return 0;
}