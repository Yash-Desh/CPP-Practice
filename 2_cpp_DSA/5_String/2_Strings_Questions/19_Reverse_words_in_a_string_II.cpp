// Author : Yash Deshpande 
// Date : 05-07-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

void reverse(string & st)
{
    int low =0;
    int high = st.size()-1;
    while(low < high)
    {
        swap(st[low++], st[high--]);
    }
}

string reverseWords (string &st)
{
    int i=0, j=0;
    string ans = "";
    for(j=0; j<st.size(); j++)
    {
        if(st[j] != ' ')
        {
            i = j+1;
            while(i < st.size() && st[i] != ' ')
            {
                i++;
            }
            string subs = st.substr(j, i-j);
            reverse(subs);
            ans = ans + subs + ' ';
            j = i;
        }
        
    }

    ans.pop_back();

    return ans;
}


int main()
{
    string sentence = "   My  6   name is love  ";
    cout<<reverseWords(sentence)<<endl;

    return 0;
}