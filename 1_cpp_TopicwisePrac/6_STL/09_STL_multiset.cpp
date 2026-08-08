// Author : Yash Deshpande
// Data : 6-8-2022
// Tutor : Luv , Striver

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // // multisets are very similar to sets , but allow repeated elements
    // // multisets are a ordered set of elements
    // // Internal implementation : using red black trees

    // multiset <string> s;

    // // inserting elements in set , time = O(log(n))
    // s.insert("abc");       // {"abc"}
    // s.insert("zeg");       // {"abc","zeg"}
    // s.insert("hell");      // {"abc","hell","zeg"}  --> stored in lexicographic order
    // s.insert("tcs");       // {"abc","hell","tcs","zeg"}
    // s.insert("abc");       // {"abc","abc","hell","tcs","zeg"}
    // s.emplace("zeg");      // {"abc","abc","hell","tcs","zeg","zeg"}


    // // Accessing elements in a set , time = O(log(n))

    // // find() is the only method to access multiset elements
    // // when element not found , it returns the iterator to s.end()
    // // when the element is repeated , find() returns an iterator to the first instance of the element
    // auto it = s.find("abc");          
    // cout<<*it<<endl;


    // // printing set elements  

    // // using iterator
    // for(auto it1=s.begin(); it1 != s.end(); it1++)
    // {
    //     cout<<*it1<<" ";
    // }
    // cout<<endl;

    // // using for-each loops
    // for(string val : s)
    // {
    //     cout<<val<<" ";
    // }
    // cout<<endl;


    // // Deletion in multiset
    
    // // by using the element , without iterator  , time = O(log(n))
    // s.erase("abc");              // {"hell","tcs","zeg"}   -> all instances of the element are deleted

    // // using iterator
    // auto it3 = s.find("zeg");    // {"hell","tcs","zeg"}   -> only the instance pointed by the iterator is deleted
    // s.erase(it3); 


    // iterator to last element
    multiset <int> ms = {11,27,5,62,6,6};      // {5,6,6,11,27,62}
    // M1
    auto itr1 = ms.end();       // iterator to beyond last element
    itr1--;
    cout<<*itr1<<endl;
    // M2
    auto itr2 = --ms.end();
    cout<<*itr2<<endl;

    // NOTE : to get an iterator to last element ,
    //        it is invalid to write auto it = ms.end()--;




    // NOTE : say you have a set of integers,
    //        set sorts in ascending order
    //        but you want to sort in descending order, methods to do this are
    //        1. sort in ascending , traverse in reverse order
    //        2. sort in descending by adding "greater<int>"    ->  set <int, greater<int>>
    //        3. input the negative of the integers in the set, so that the largest positive 
    //           integer becomes the smallest -ve integer , then u may traverse the set in forward direction


    // rest of the iterators / functions are similar to maps like begin() , end() swap() empty(), size(), clear()

    return 0;
}
