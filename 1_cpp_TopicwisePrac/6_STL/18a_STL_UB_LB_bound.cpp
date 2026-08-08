// Author : Yash Deshpande
// Date : 11-08-2022
// Tutor : CodeWithHarry , Luv , Striver

#include <bits/stdc++.h>
using namespace std;

/*

For the upper-bound & lower-bound algorithms to work , 
the given ds must be sorted
For sorted ds the time is O(log(n))
For unsorted DS, the time O(N)

The result of these functions is the location of an element
For arrays it returns a pointer
For vectors it returns an iterator

LB returns location to element or the nge of the element to be found if it is not present

UB returns location to the nge of the element to be found

** If no such address exist , then it gives the location next to the last element outside the indexes 
given for searching

The element to be searched may or may not exist within the given ds

In LB if the element to be found is present multiple times , then it returns the location
of the 1st occurence of that element

HERE : The use of UB & LB is shown for arrays & vectors

*/

int main()
{
    // #################################
    // Using UB & LB with arrays
    // #################################

    // // creating an array
    // int n = 6;
    // int a[n] = {4, 5, 5, 25, 7, 8};

    // // sorting the array 
    // // Sorting is very important for UB & LB
    // sort(a,a+n);

    // // printing the sorted array
    // for(int i=0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;                         // 4 5 5 7 8 25

    // // LB: Example-1: Element present in the array
    // int *ptr1 = lower_bound(a,a+n,5);    // syntax = lower_bnd ([start, end), value) indexes are given like in sort()
    // cout<<*ptr1<<endl;                   // returns 5 or any element greater than 5 if 5 
    //                                      // is not present

    // // LB: Example-2: Element not present in the array
    // ptr1 = lower_bound(a, a+n, 6);
    // cout<<(*ptr1)<<endl;                // 7

    // // LB: Example-3: Element larger than largest array element 
    // ptr1 = lower_bound(a, a+n, 26);
    // cout<<(*ptr1)<<endl;                // some garbage value

    // int *ptr2 = upper_bound(a,a+4, 17); 
    // cout<<*ptr2<<endl;                  // 8
    

    // #################################
    // Using UB & LB with vectors
    // #################################

    // int n = 6;
    // vector<int> a = {4, 5, 5, 25, 7, 8};

    // // sorting the array 
    // // Sorting is very important for UB & LB
    // sort(a.begin(),a.end());

    // // printing the sorted array
    // for(int i=0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;


    // // using UB & LB
    // auto it = lower_bound(a.begin(), a.end(),55);    // syntax = lower_bnd ([start, end), value) indexes are given like in sort()
    // if(it == a.end())
    // {
    //     cout<<"NOT FOUND"<<endl;
    // }
    // else{
    //     cout<<*it<<endl;
    // }

    // auto it1 = upper_bound(a.begin()+4, a.end(), 17);
    // cout<<*it1<<endl;


    // #################################
    // Using UB & LB with sets & maps
    // #################################
    set<int> s = {4, 5, 5, 25, 7, 8};

    // Using LB 
    auto it = s.lower_bound(5);
    cout<<(*it)<<endl;

    return 0;
}