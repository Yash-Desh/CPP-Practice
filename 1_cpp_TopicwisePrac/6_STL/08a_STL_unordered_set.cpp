// Author : Yash Deshpande
// Data : 6-8-2022
// Tutor : Luv , Striver

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
    // Unordered Sets are very similar to sets
    // It is a collection of unique elements in random order
    // Internal implementation : using hash tables

    unordered_set<string> s;

    // inserting elements in set , time = O(1)
    s.insert("abc");       // {"abc"}
    s.insert("zeg");       // {"abc","zeg"}
    s.insert("hell");      // {"abc","hell","zeg"}  
    s.insert("tcs");       // {"abc","hell","tcs","zeg"}
    s.emplace("inf");      // {"abc","hell","inf","tcs","zeg"}


    // Accessing elements in a set , time = O(1)

    // find() is the only method to access set elements
    // when element not found , it returns the iterator to s.end()
    auto it = s.find("abc");          
    cout<<*it<<endl;


    // printing set elements  

    // using iterator
    for(auto it1=s.begin(); it != s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // using for-each loops
    for(string val : s)
    {
        cout<<val<<" ";
    }
    cout<<endl;


    // Deletion in set
    
    // by using the element , without iterator  , time = O(1)
    s.erase("inf");              // {"abc","hell","tcs","zeg"}

    // using iterator
    auto it3 = s.find("zeg");    // {"abc","hell","tcs"} 
    s.erase(it3); 

    // checking whether a certain element is present in the set
    int cnt = s.count("5rr6");  // returns 1 if element found , 0 if not found 
    cout<<cnt<<endl;


    // NOTE : unordered_sets of only simple data types like int , float , char etc is possible 
    //        for complex datatype like vectors , pairs , maps we cannot make unordered_set
    //        normal sets have no such limitations

    return 0;
}