// Author : Yash Deshpande
// Data : 6-8-2022
// Tutor : Luv , Striver

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // // Sets are very similar to maps , but just without the value part of maps
    // // Sets are a ordered set of unique elements
    // // Internal implementation : using red black trees

    // set <string> s;

    // // inserting elements in set , time = O(log(n))
    // s.insert("abc");       // {"abc"}
    // s.insert("zeg");       // {"abc","zeg"}
    // s.insert("hell");      // {"abc","hell","zeg"}  --> stored in lexicographic order
    // s.insert("tcs");       // {"abc","hell","tcs","zeg"}
    // s.insert("inf");       // {"abc","hell","inf","tcs","zeg"}


    // // Accessing elements in a set , time = O(log(n))

    // // find() is the only method to access set elements
    // // when element not found , it returns the iterator to s.end()
    // auto it = s.find("abc");          
    // cout<<*it<<endl;


    // // printing set elements  

    // // using iterator
    // for(auto it1=s.begin(); it != s.end(); it++)
    // {
    //     cout<<*it<<" ";
    // }
    // cout<<endl;

    // // using for-each loops
    // for(string val : s)
    // {
    //     cout<<val<<" ";
    // }
    // cout<<endl;


    // // Deletion in set
    
    // // by using the element , without iterator  , time = O(log(n))
    // s.erase("inf");              // {"abc","hell","tcs","zeg"}

    // // using iterator
    // auto it3 = s.find("zeg");    // {"abc","hell","tcs"} 
    // s.erase(it3); 

    // // erasing all the elements within a range
    // auto it4 = s.find("hell");
    // auto it5 = s.find("tcs");
    // s.erase(it4,it5);   // {1,44,53}   // [first, last)



    // // checking whether a certain element is present in the set, time = O(log(n))
    // int cnt = s.count("5rr6");  // returns 1 if element found , 0 if not found 
    // cout<<cnt<<endl;



    // Comparison between pairs 
    set <int> s1 , s2;
    s1 = {1,7,5,6};
    s2 = {3,4,1};
    cout<<(s1<s2)<<endl;      // 1

    // NOTE : comparison b/w 2  sets with comparison operator
    //        compares the 1st element of both pairs
    //        returns 1 if true , 0 if false
    //        if 1st element of both sets same , then compares the 2nd of both sets 
    //        and so on until the 1st point of difference 


    // NOTE : say you have a set of integers,
    //        set sorts in ascending order
    //        but you want to sort in descending order, methods to do this are
    //        1. sort in ascending , traverse in reverse order
    //        2. sort in descending by adding "greater<int>"    ->  set <int, greater<int>>
    //        3. input the negative of the integers in the set, so that the largest positive 
    //           integer becomes the smallest -ve integer , then u may traverse the set in forward direction


    // rest of the iterators / functions are similar to maps like begin() , end() swap() empty()

    return 0;
}
