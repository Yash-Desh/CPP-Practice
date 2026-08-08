#include <bits/stdc++.h>
using namespace std;

int main()
{
    // All the functions of unorder_maps is same as maps

    // Internal implementation : using hash tables
    // Time complexity : O(1)  ... for insertion & deletion


    unordered_map <int, string> ump;

    // inserting in an unordered map  , time = O(1)
    ump[1] = "abc";
    ump[7] = "adc";
    ump[4] = "sdt";
    ump[5] = "ctc";
    ump[2] = "tds";

    // display unsorted map
    for(auto it = ump.begin(); it != ump.end(); it++)
    {
        cout<<(*it).first<<" "<<it->second<<endl;
    }
    cout<<endl;

    
    // functions similar to maps take O(1) time 

    // find() method : returns an iterator to the pair consisting the given "key"  , time : O(1)
    //                 if such key is NOT present , then it returns mp.end()
    auto it = ump.find(3);    
    cout<<"key = "<<it->first<<" & value = "<<it->second<<endl;


    // deleting elements in a map

    // using keys   , time = O(1)
    ump.erase(3);


    // NOTE : unordered_maps of only simple data types like int , float , char etc is possible 
    //        for complex datatype like vectors , pairs , sets we cannot make unordered_map 
    //        normal maps have no such limitations 



    // multimap is very similar to map , the only difference being that it can store repeated keys 
    multimap <int , string> mmp;  // declaration

    // multimaps are not used frequently
    
    return 0;
}