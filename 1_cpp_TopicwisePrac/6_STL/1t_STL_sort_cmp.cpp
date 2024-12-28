// Author : Yash Deshpande
// Date : 11-08-2022
// Tutor : CodeWithHarry , Luv , Striver

/*
Default behavior of the sort() in STL is in ascending order
But using comparator function , we can define our own custom sorting behavior
But the comparator function in the STL has a different behavior than the should_i_swap()
we have seen here
comparator follows the rule : If you want to swap , return a false
so in order to prevent confusion while coding remember to : return what u want

There are also some inbuilt comparator functions like "greater<int>" 
But then there are  a limited number of in-built comparators & also syntax for them must be remembered
So it is better to define your own comparator function

*/

#include <bits/stdc++.h>
using namespace std;

// // function to define custom sorting behavior for a vector <int>
// bool should_i_swap(int a , int b)
// {
//     // condition to swap in ascending order
//     // this can easily be made to sort in descending order by making (a<b)
//     if( a > b)
//     {
//         return true;
//     }
//     return false;
// }


// // function to define a custom sorting behavior for a vector of pair
// bool should_i_swap (pair<int , int> a, pair<int, int> b)
// {
//     if(a.first != b.first)
//     {
//         if(a.first>b.first)
//             return true;
//         return false;
//     }
//     else
//     {
//         if(a.second < b.second)
//             return true;
//         return false;
//     }
// }


// comparator function to define custom sorting behavior for a vector of pair
bool cmp (pair<int , int> a, pair<int, int> b)
{
    if(a.first != b.first)
        return a.first < b.first;

    else
        return a.second > b.second;
}


// comparator function to define custom sorting behavior for a vector of integers
bool cmp1 (int a, int b)
{
    return a < b;       // for ascending order
    // return a>b       // for descending order
} 

int main()
{
    // Understanding what a comparator function does & how it works

    // // sorting a vector <int>
    // vector <int> v = {12,4,64,31,105,-13,9};
    // int size = v.size();

    // // Basic sorting  : selection sort in ascending order
    // for(int i=0; i<size; i++)
    // {
    //     for(int j=i+1; j<size; j++)
    //     {
    //         // if(v[i] > v[j])    // this if condition here defines how the ds is sorted
    //         // {
    //         //     swap(v[j], v[i]);
    //         // }

    //         // so we created function to define sorting method 
    //         // by making desired changes to the function we can define the sorting behavior
    //         // such a function is called a comparator
    //         if(should_i_swap(v[i], v[j]))
    //         {
    //             swap(v[j], v[i]);
    //         }
    //     }
    // }

    // // loop to print a vector
    // for(int &num : v)
    // {
    //     cout<<num<<" ";
    // }
    // cout<<endl;



    // // sorting a vector of pair
    // vector <pair<int, int>> v = {{9,4},{5,7},{5,3},{3,1},{2,8},{3,4}};
    // int size = v.size();

    // // Basic sorting  : selection sort in ascending order
    // for(int i=0; i<size; i++)
    // {
    //     for(int j=i+1; j<size; j++)
    //     {
    //         // if(v[i] > v[j])    // this if condition here defines how the ds is sorted
    //         // {
    //         //     swap(v[j], v[i]);
    //         // }

    //         // so we created function to define sorting method 
    //         // by making desired changes to the function we can define the sorting behavior
    //         // such a function is called a comparator
    //         if(should_i_swap(v[i], v[j]))
    //         {
    //             swap(v[j], v[i]);
    //         }
    //     }
    // }

    // // loop to print the sorted vector of pairs
    // for(pair<int, int> pr : v)
    // {
    //     cout<<pr.first<<" "<<pr.second<<endl;
    // }
    // cout<<endl;


    // Using comparator function to sort a vector of pairs

    vector <pair<int, int>> v = {{9,4},{5,7},{5,3},{3,1},{2,8},{3,4}};
    int size = v.size();

    sort(v.begin(), v.end(), cmp);    // Notice that no () were used after cmp

    // loop to print the sorted vector of pairs
    for(pair<int, int> pr : v)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    cout<<endl;
    




    return 0;
}