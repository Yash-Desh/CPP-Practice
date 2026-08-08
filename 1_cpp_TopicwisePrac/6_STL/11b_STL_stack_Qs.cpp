// Author : Yash Deshpande
// Date : 9-08-2022
// Tutor : CodeWithHarry , Luv , Striver


// Q. Balanced Brackets (on HackerRank) : solved using a different technique, to prevent the complex if-else technique

#include <bits/stdc++.h>
using namespace std;

// global unordered map , 
unordered_map <char, int> symbols = {{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};

string isBalanced(string s) {
    stack <char> st;
    for(char ch : s)
    {
        // opening brackets
        if(symbols[ch] < 0)
        {
            st.push(ch);
        }
        // closing brackets
        else
        {
            // on encountering a closing bracket , check if stack is empty
            if(st.empty())
            {
                return "NO";
            }
            char top = st.top();
            st.pop();
            if(symbols[top] + symbols[ch] != 0)
            {
                return "NO";
            }
        }
    }
    if(st.empty())
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        cout<<isBalanced(s)<<endl;
    }
    return 0;
}