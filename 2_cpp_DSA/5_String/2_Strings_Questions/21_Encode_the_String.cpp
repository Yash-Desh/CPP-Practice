// Author : Yash Deshpande
// Date : 09-08-2022
// Tutor : Love Babbar Weekly Test - 4

#include <iostream>
using namespace std;

string encodeString(string &s, int n) 
{
    // Write your code here.
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            s[i] = s[i]+1;
        }
        else
        {
            s[i] = s[i]-1;
        }
    }
    return s;
}

int main()
{
    
    return 0;
}