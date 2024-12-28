// Author : Yash Deshpande
// Date : 12-8-22
// Solved : Luv STL series : 3rd CP contest
// My Approach : null

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,k,f;
        cin>>N>>k>>f;
        vector <pair<int,int>> vp;
        for(int i=0; i<N; i++)
        {
            int dist, food;
            cin>>dist>>food;
            vp.push_back({k-dist,food});
        }

        sort(vp.begin(), vp.end());
        multiset <int> ms;
        int curr = 0;
        bool can_reach = true;
        int ans = 0;
        for(int i=1 ; i<k ; i++)
        {
            f--;
            if(i == vp[curr].first)
            {
                ms.insert(vp[curr].second);
                curr++;
            }

            if(f == 0)
            {
                if(ms.size()== 0)
                {
                    can_reach = false;
                    break;
                }
            }
            else
            {
                auto it = --ms.end();
                f = f + *it;
                ms.erase(it);
                ans++;
            }
        }
        if(can_reach)
        {
            cout<<ans;
        }
        else
        {
            cout<<-1;
        }

    }
    return 0;
}