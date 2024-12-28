#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;

        if(n==1 && m==1)
        {
            cout<<0<<endl;
            continue;
        }

        // Deciding larger and smaller number
        int small = min(n,m);  
        int large = max(n,m);

        int half_sm;
        if(n%2 == 0)
        {
            half_sm = small/2-1;
        }
        else
        {
            half_sm=small/2;
        }
        int remaining;
        if(small == m)
            remaining = m-half_sm-1;
        else 
            remaining = n-half_sm-1;

        cout<<2*half_sm + large + 2*remaining<<endl;
        
    }
    return 0;
}