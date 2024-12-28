// Author : Yash Deshpande
// Date : 10-09-2022
// Topic : Strings
// Tutor : 450 DSA


#include <bits/stdc++.h>
using namespace std;


int countRev (string s)
{
    // your code here
    
    // Experimental Approach
    // Based on the approach taught by LUV
    // Every '{' = 1 & '}' = -1
    // Traversing through the string we find
    // the total score
    // if total score odd , return -1
    // else return cnt + score / 2 
    int score = 0;
    int cntReversal = 0;
    for(int i=0; i< s.size(); i++)
    {
        if(s[i] == '{')
        {
            score++;
        }
        else 
        {
            score--;
        }
        if(score < 0)
        {
            // whenever 
            score = -score;
            cntReversal++;
        }
    }
    if(score&1)
    {
        return -1;
    }
    else
    {
        cntReversal += score /2;
        return cntReversal;
    }
}




int countRev (string s)
{
    // your code here
    
    // corner case
    if(s.size() & 1)
        return -1;
    
    else
    {
        // maintain a count of all unbalanced
        // opening & closing brackets seperately
        
        int c1 = 0; // for opening brackets
        int c2 = 0; // for closing brackets
        stack <char> st;
        for(int i=0; i< s.size(); i++)
        {
            if(s[i] == '{')
            {
                st.push('{');
                c1++;
            }
            else
            {
                if(st.empty())
                    c2++;
                    
                else
                {
                    st.pop();
                    c1--;
                }
            }
        }
        c2 = ceil((float)c2/2);
        c1 = ceil((float)c1/2);
        return c1 + c2  ;
    }
}


int main()
{
    
    return 0;
}