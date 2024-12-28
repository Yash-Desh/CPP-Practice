#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int diffCnt = 0;
        int A1 =0, A2=0;

        int arr1[n], arr2[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr1[i];
            if(arr1[i] == 1)
                A1++;
        }

        for(int i=0; i<n; i++)
        {
            cin>>arr2[i];
            if(arr2[i] == 1)
                A2++;

            if(arr1[i] != arr2[i])
                diffCnt++;
        }

        if(diffCnt == 0)
        {
            cout<<0<<endl;
        }
        else if(diffCnt != 0 && A1==A2)
        {
            cout<<1<<endl;
        }
        else
        {
            if(diffCnt == abs(A1-A2))
            {
                cout<<diffCnt<<endl;
            }

            else
            {
                cout<<abs(A1-A2) +1<<endl;
            }
        }
    }
    return 0;
}