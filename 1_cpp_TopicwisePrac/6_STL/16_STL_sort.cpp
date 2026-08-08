// Author : Yash Deshpande
// Date : 10-08-2022
// Tutor : CodeWithHarry , Luv , Striver

#include <bits/stdc++.h>
using namespace std;

/*

This sorting is known as introsort
It is a combination of heap sort , quick sort , insertion sort
It is the most optimized sorting technique
TC = O(N*log(N))  ...in all cases

*/

int main()
{

    // // Sorting an array
    // int n;
    // cin>>n;
    // int a1[n];
    // for(int i=0; i<n; i++)
    // {
    //     cin>>a1[i];
    // }
    // sort(a1,a1+n);   
    // // NOTE : sort takes 2 parameters
    // //        the 1st is a pointer to starting index , from where we need to sort
    // //        the 2nd is a pointer to the next index as until where we need to sort 
    // //        [start, end)

    // for(int i=0; i<n; i++)
    // {
    //     cout<<a1[i]<<" ";
    // }
    // cout<<endl;


    // Sorting a vector
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end());   
    // NOTE : sort takes 2 parameters
    //        the 1st is a iterator to starting index , from where we need to sort
    //        the 2nd is a iterator to the next index as until where we need to sort 
    //        [start, end)

    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
