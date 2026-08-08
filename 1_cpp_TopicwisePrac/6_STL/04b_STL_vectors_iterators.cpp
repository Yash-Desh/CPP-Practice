// Author : Yash Deshpande
// Date : 4-08-2022
// Tutor : CodeWithHarry , Luv , Striver


#include <bits/stdc++.h>
using namespace std;

// Note : Accessing out of bound elements in vectors will lead
// to segmentation faults 


// Simple function to print vector elements 
// to iterate over a vector using for loop & indices
void printVec (vector <int> V)    // <data_type> change datatype as per need to print
{
   for(int i=0; i<V.size(); i++)
   {
      cout<<V[i]<<" ";
   }
   cout<<endl;
}



int main()
{
    // Iterators
    // iterators point at the memory address of the vector elements
    // Iterators in vectors are of continuous nature since memory storage is continuous

    // vector <int> v = {1,3,5,7,9,12};
    // vector <int> :: iterator it1 = v.begin();   // points to the memory address of first element

    // // iterator arithmetic
    // cout<<"*(it) = "<<*it1<<endl;        // 1

    // it1++;                               // moves to next iterator 
    // cout<<"*(it) = "<<*it1<<endl;        // 3

    // it1 = it1 + 1;                       // moves to next memory location
    // cout<<"*(it) = "<<*it1<<endl;        // 5

    // cout<<"*(it+1) = "<<*(it1+1)<<endl;  // 7 , note that it still points at 5

    // vector <int> :: iterator it2;
    // it2 = it1+2;
    // cout<<"(*it2) = "<<*it2<<endl;        // 9 

    // NOTE : In vectors , due to continuous memory allocation, 
    //        next iterator is the same as next memory location
    //        thus  it++ <==> it+1 


    // some other iterators

    // vector <int> :: iterator it2 = v.end();        // points at memory location next to the last element in the vector 
    
    // // vector <int> :: iterator it3 = v.rend();    // some unused iterators

    // // vector <int> :: iterator it4 = v.rbegin();



    // // for loop using iterator
    // vector <int> v1 = {1,9,8,7,6,5,4,35};
    // for(vector<int> :: iterator it3 = v1.begin(); it3 != v1.end(); it3++)  
    // {
    //     cout<<*it3<<" ";
    // }
    // cout<<endl;


    // // Iterators in short

    // // auto keyword : introduced in C++ 11
    // vector <int> v1 = {1,9,8,7,6,5,4,35};
    // for(auto it4=v1.begin(); it4 != v1.end(); it4++)
    // {
    //     cout<<*it4<<" ";
    // }
    // cout<<endl;


    
    // traversing a vector of pairs using iterator  :  arrow operator (->)
    vector <pair<int, int>> vp = {{1,2},{3,4},{5,6}};

    // vector <pair<int, int>> :: iterator itp;
    // for(itp = vp.begin(); itp != vp.end(); itp++)
    // {
    //     cout<<(*itp).first<<", "<<itp->second<<endl;      //  NOTE : (*itp).first <==> itp->first
    // }


    // // for-each loop on a vector of pairs (does not use iterators)
    // for(pair <int, int> ele : vp) 
    // {
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }
    // cout<<endl;


    // Functions performed using iterators

    // // deletion in a vector

    // vector<int> v2 = {34,45,36,12,15,99,87,63,112};

    // // // deleting a single element
    // auto it = v2.begin()+2;     // points at element 36
    // v2.erase(it);               // {34,45,12,15,99,87,63,112}
    // printVec(v2);
    

    // // deleting a range of elements 
    // v2.erase(v2.begin()+1,v2.begin()+4);   //  [start,end)
    // printVec(v2);                          // {34,99,87,63,112}


    // // Insert function

    // vector <int> v3(2,100);                            // {100,100}
    
    // // insert at beginning
    // v3.insert(v3.begin(),35);                         // {35,100,100}
    // printVec(v3);
    
    // // insert after any position
    // v3.insert(v3.begin()+1 ,45);                      // syntax : insert(iterator , value)
    // printVec(v3);                                     // {35,45,100,100}
    
    // // insert a value multiple times 
    // v3.insert(v3.begin()+2 , 3 ,77);                  // syntax : insert (iterator, number of elements, value)
    // printVec(v3);                                     // {35, 45, 77, 77, 77, 100, 100}


    // // inserting portions of 1 vector into another vector
    // vector <int> copy_vec(5,50);                                // {50,50,50,50,50}
    // v3.insert(v3.begin(),copy_vec.begin(),copy_vec.end());      // {50,50,50,50,50,35,45,77,77,77,100,100}
    // printVec(v3);


    return 0;
}