// Author : Yash Deshpande
// Date : 30-03-2022

#include <bits/stdc++.h>
using namespace std;

// Map is a DS that stores key-value pair
// In "maps" the elements are stored in a sorted order of unique key values
// Internal implementation of maps is in the DS "red black trees"
int main()
{
    // // declaring a map
    map <int, string> mp;

    // // inserting in a map
    mp[12] = "abc";    // 12 -> abc  , time = O(log(n))
    mp[74] = "vdt";    // 74 -> vdt
    // mp[4] = "hgt";
    // mp[5] = "llsm";

    // // inserting using a insert() method
    // mp.insert({3,"tif"});   // a pair<int, string> is given

    // // inserting using emplace()
    // mp.emplace(3,"stif");  // all keys are unique , this stmt changes the value for the key 3

    // /*
    // time for insertion generally is log(n) 
    // but when the keys are string , insertion operation takes place
    // by comparing it with all other keys already present in map
    // thus then time of insertion is "time for string comparison" * log(n) 
    
    // */



    // // NOTE : Accessing elements in a map takes log(n) time

    cout<<mp[12]<<endl;     // abc
    cout<<mp[51]<<endl;     // no key exist with value 51, a new entry got created with key=51 & value = null or 0 or empty string
    
    
    // Note the difference between 
    cout<<mp.at(101)<<endl;     // This will give error
    cout<<mp[101]<<endl;        // This will create a new entry & return value

    // Determine the presence of a specific key in the map using  count() function
    cout<<mp.count(101)<<endl;
    
    // // Printing map elements by iterating over them , accessing n elements thus takes nlog(n) 

    // // declaring an iterator for the map  , points to a pair hving key-value
    // map<int, string> :: iterator iter;

    // for (iter = mp.begin(); iter != mp.end(); iter++)
    // {
    //     cout<<(*iter).first<<" : "<<(*iter).second<<endl;    // (*iter).first <==>  iter->first
    // }


    // // looping over the map can also be done using for-each loop & auto
    // for(auto pr : mp)         // pr is of pair<int, string> datatype
    // {
    //     cout<<"key = "<<pr.first<<" &  value = "<<pr.second<<endl;
    // }

    // // Size of map : Number of elements in map 
    // cout<<"Size of map = "<<mp.size()<<endl;


    // find() method : returns an iterator to the pair consisting the given "key"  , time : O(log(n))
    //                 if such key is NOT present , then it returns mp.end()
    // map <int,int> mp; 
    // auto it = mp.find(3); 
    // if(it == mp.end())
    // {
    //     cout<<"not found"<<endl;
    // }   
    // else
    // {
    //     cout<<"key = "<<it->first<<" & value = "<<it->second<<endl;
    // }
    


    // // deleting elements in a map

    // // using keys   , time = O(log(n))
    // mp.erase(3);

    // // using iterators
    // auto it1 = mp.find(5);
    // mp.erase(it1);           

    // // NOTE : use only when iterator points to a valid pair in the map 
    // auto it2 = mp.find(13);     // No such key exist so find() returns mp.end()
    // // mp.erase(it2);           // This will give a segmentation fault

    // // clearing the entire map
    // mp.clear();

    // // map of pair
    // map <pair <int,int>, int> mpp3;
    // mpp3[{2,3}] = 10;  // key a pair {2,3} , value = 10


    // // NOTE : say you have a map of integers as keys
    // //        map sorts in ascending order
    // //        but you want to sort in descending order, methods to do this are
    // //        1. sort in ascending , traverse in reverse order
    // //        2. sort in descending by adding "greater<int>"    ->  map <int, int , greater<int>>
    // //        3. input the negative of the integers in the map, so that the largest positive 
    // //           integer becomes the smallest -ve integer , then u may traverse the map in forward direction

    return 0;
}