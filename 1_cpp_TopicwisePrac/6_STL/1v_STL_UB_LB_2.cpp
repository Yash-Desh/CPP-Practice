// Author : Yash Deshpande
// Date : 11-08-2022
// Tutor : CodeWithHarry , Luv , Striver

#include <bits/stdc++.h>
using namespace std;

/*
Demonstrate the use of UB & LB in case of ordered ds like 
maps & sets 

In case of maps & sets, the upper_bound & lower_bound functions 
are called differently to maintain time complexity of O(NlogN).

--> Luv has explained this concept in his video, refer it for mored detail.
*/

int main()
{
    set <int> st;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        st.insert(x);
    }

    // For ordered ds , sorting need not be done

    // Using UB & LB
    auto it = st.lower_bound(15);   // Notice that for maps & sets , no indices were givens
    if(it == st.end())
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<*it<<endl;
    }

    auto it1 = st.upper_bound(75);   // Notice that for maps & sets , no indices were givens
    if(it1 == st.end())
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<*it1<<endl;
    }


    return 0;
}