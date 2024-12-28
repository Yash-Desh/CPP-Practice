// Author : Yash Deshpande
// Date : 11-08-2022
// Tutor : CodeWithHarry , Luv , Striver

#include <bits/stdc++.h>
using namespace std;

/*

For the upper-bound & lower-bound algorithms to work , 
the given ds must be sorted
For sorted ds the time is O(log(n))
The result of these functions is the location of an element
For arrays it returns a pointer
For vectors it returns an iterator

LB returns location to element or the nge of the element to be found if it is not present

UB returns location to the nge of the element to be found

If no such address exist , then it gives the location next to the last element outside the indexes 
given for searching

The element to be searched may or may not exist within the given ds

In LB if the element to be found is present multiple times , then it returns the location
of the 1st occurence of that element

HERE : The use of UB & LB is shown for arrays & vectors

*/

int main()
{
    // Using UB & LB with arrays

    // // creating an array
    // int n;
    // cin>>n;         // number of elements in the array
    // int a[n];
    // for(int i=0; i<n; i++)
    // {
    //     cin>>a[i];
    // }
    // cout<<endl;

    // // sorting the array 
    // // Sorting is very important for UB & LB
    // sort(a,a+n);

    // // printing the sorted array
    // for(int i=0; i<n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    // // using UB & LB
    // int *ptr1 = lower_bound(a,a+n,5);    // syntax = lower_bnd ([start, end), value) indexes are given like in sort()
    // cout<<*ptr1<<endl;                   // returns 5 or any element greater than 5 if 5 
    //                                      // is not present

    // int *ptr2 = upper_bound(a,a+4, 17);
    // cout<<*ptr2<<endl;
    


    // Using UB & LB with vectors

    int n;
    cin>>n;         // number of elements in the array
    vector <int> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<endl;

    // sorting the array 
    // Sorting is very important for UB & LB
    sort(a.begin(),a.end());

    // printing the sorted array
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;


    // using UB & LB
    auto it = lower_bound(a.begin(), a.end(),55);    // syntax = lower_bnd ([start, end), value) indexes are given like in sort()
    if(it == a.end())
    {
        cout<<"NOT FOUND"<<endl;
    }
    else{
        cout<<*it<<endl;
    }

    auto it1 = upper_bound(a.begin()+4, a.end(), 17);
    cout<<*it1<<endl;

    return 0;
}