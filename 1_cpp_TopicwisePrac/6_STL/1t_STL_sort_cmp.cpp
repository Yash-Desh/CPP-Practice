// Author : Yash Deshpande
// Date : 11-08-2022
// Tutor : CodeWithHarry , Luv , Striver
// Link   : (Luv) https://youtu.be/3pvZhwp0U9w?si=nNWKPaMXhI54AqVL 

#include <bits/stdc++.h>
using namespace std;

// File Covers 2 types of comparator functions
// 1. comparator function for manually defined sorting functions
// 2. comparator function for std::sort()

// Comparator functions for manually defined sorting functions ----------------- // 

// defines custom sorting behavior for a vector<int>
bool should_i_swap(int a , int b) {
    // condition to swap in ascending order
    if( a > b) { return true; }
    return false;

    // // condition to swap in descending order
    // if( a < b) { return true; }
    // return false;
}

// defines a custom sorting behavior for a vector<pair<int, int>>
// pair<int, int> p -> p.first is sorted in ascending order
//                  -> p.second is sorted in descending order
bool should_i_swap (pair<int , int> a, pair<int, int> b) {
    if(a.first != b.first) {
        if(a.first>b.first)
            return true;
        return false;
    }
    else {
        if(a.second < b.second)
            return true;
        return false;
    }
}

// ----------------------------------------------------------------------------- //

// RULE: cmp(a, b) returns true if a should appear before b in the final sorted order.
// return a < b = ascending
// return a > b = descending.


// defines custom sorting behavior for a vector<int> for std::sort()
bool cmp1 (int a, int b) {
    return a < b;       // for ascending order
    // return a>b       // for descending order
} 

// defines custom sorting behavior for a vector<pair<int, int>> for std::sort()
// pair<int, int> p -> p.first is sorted in descending order
//                  -> p.second is sorted in ascending order
bool cmp (pair<int , int> a, pair<int, int> b) {
    // Approach-1: 
    if(a.first != b.first) {
        if(a.first>b.first) { return true; }    
        return false;
    }
    else {
        if(a.second < b.second) { return true; }
        return false;
    }

    // Approach-2: 
    // if(a.first != b.first)
    //     return a.first < b.first;

    // else
    //     return a.second > b.second;
}


// ---------------------- Helper Functions ------------------------------- // 
void printVectorOfInt(vector<int> &v) {
    // loop to print a vector
    for(int &num : v) {
        cout<<num<<" ";
    }
    cout<<endl;
}

void printVectorOrPair(vector<pair<int, int>> &v) {
    // loop to print the sorted vector of pairs
    for(pair<int, int> pr : v) {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    cout<<endl;
}

int main() {
    // Understanding what a comparator function does & how it works

    // sorting a vector<int> 
    vector<int> v = {12,4,64,31,105,-13,9};
    int size = v.size();

    // Basic sorting  : selection sort in ascending order
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            // Approach-1: if-condition defines how the ds is sorted
            // if(v[i] > v[j]) {
            //     swap(v[j], v[i]);
            // }

            // Approach-2: Custom sorting behavior defined within the function
            if(should_i_swap(v[i], v[j])) {
                swap(v[j], v[i]);
            }
        }
    }

    printVectorOfInt(v);

    // ----------------------------------------------------------------------------- //

    // sorting a vector<pair<int, int>>
    vector <pair<int, int>> vp = {{9,4},{5,7},{5,3},{3,1},{2,8},{3,4}};
    int sizeP = vp.size();

    // Basic sorting  : selection sort in ascending order
    for(int i=0; i<sizeP; i++) {
        for(int j=i+1; j<sizeP; j++) {
            // Approach-1: if-condition defines how the ds is sorted
            // if(vp[i] > vp[j]) {
            //     swap(vp[j], vp[i]);
            // }

            // Approach-2: Custom sorting behavior defined within the function
            if(should_i_swap(vp[i], vp[j])) {
                swap(vp[j], vp[i]);
            }
        }
    }

    printVectorOrPair(vp);

    // ----------------------------------------------------------------------------- //
    
    // Using comparator function to sort a vector of pairs
    vector <pair<int, int>> vc = {{9,4},{5,7},{5,3},{3,1},{2,8},{3,4}};

    sort(vc.begin(), vc.end(), cmp);    // Notice that no () were used after cmp
    printVectorOrPair(vc);
    
    
    // built-in comparators greater<>
    // pair<int, int> p -> p.first is sorted in descending order
    //                  -> p.second is sorted in descending order
    sort(vc.begin(), vc.end(), greater<pair<int, int>>());
    printVectorOrPair(vc);

    return 0;
}

/*

Luv Said this in his video but Claude disagrees---------------------------------------------------------
Default behavior of the sort() in STL is in ascending order
But using comparator function , we can define our own custom sorting behavior
But the comparator function in the STL has a different behavior than the should_i_swap()
we have seen here
comparator follows the rule : If you want to swap , return a false
so in order to prevent confusion while coding remember to : return what u want

There are also some inbuilt comparator functions like "greater<int>"
But then there are  a limited number of in-built comparators & also syntax for them must be remembered
So it is better to define your own comparator function
--------------------------------------------------------------------------------------------------------

Note (Claude Opus 4.8, 2026-07-23):
Canonical rule for std::sort comparators: cmp(a, b) returns true if 'a' should
come BEFORE 'b' in the final sorted order (read it as "does the first argument
come first?", NOT "should I swap?"). Map it to '<': return a < b -> ascending,
return a > b -> descending. std::sort also requires a strict weak ordering, so
for equal elements the comparator must return false both ways.
*/