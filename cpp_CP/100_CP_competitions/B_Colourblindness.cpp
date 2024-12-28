#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int size;
        string str1;
        string str2;
        cin>>size>>str1>>str2;
        int i;
        for(i=0; i<size; i++)
        {
            if(str1[i] != str2[i])
            {
                if(str1[i] == 'R' || str2[i] == 'R')
                {
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        if(i == size)
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}