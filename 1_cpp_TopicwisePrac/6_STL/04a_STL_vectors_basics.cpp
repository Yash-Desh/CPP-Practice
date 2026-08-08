// Author : Yash Deshpande
// Date : 4-08-2022
// Tutor : CodeWithHarry , Luv , Striver

// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>
using namespace std;


// Note : Accessing out of bound elements in vectors will lead to segmentation faults 


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
   // // Declaring Vectors

   // // zero length integer vector
   // vector<int> vec1;                                   //  {}
   // printVec(vec1);   

   // // Declaring & initializing in the same line
   // vector<int> vec2 = {3, 78, 91, 7, 9};              // {3,78,91,7,9}
   // printVec(vec2);

   // // special declarations
   // vector<int> vec3(5, 100);                          // {100,100,100,100,100}
   // printVec(vec3);

   // vector<int> vec4(5);                               // {gv,gv,gv,gv,gv}  -> gv = garbage value
   // printVec(vec4);


   // // Appending new elements to a Vector
   // vector<int> vec1;       //  {}
   // vec1.push_back(44);     //  {44}     appends the vector , time = O(1)
   // vec1.emplace_back(63);  //  {44,63}  similar to push_back but more efficient


   // // Delete the last element : pop_back()  , time = O(1)
   // vector<int> v2 = {1, 2, 4, 7, 16, 49}; // {1,2,4,7,16,49}
   // v2.pop_back();                         // {1,2,4,7,16}

   // -------------------------------------------------------------------

   // Size & Capacity of a vector 

   // // size of a vector : size()  , time = O(1)
   // vector <int> vec1 = {34,6,8,15,47,91};
   // cout << "Size of the vector vec1 = " << vec1.size() << endl;   // 6


   // // Capacity of a vector 
   // vector <int> v = {1,4,6};
   // cout<<"Capacity = "<<v.capacity()<<endl;      // 4
   // cout<<"Size = "<<v.size()<<endl;              // 3

   // NOTE : Capcity & size are 2 different things
   //        Capacity is the total space alloted to the vector in memory
   //        Size is the total number of elements present in the vector
   //        Memory / Capacity is always alloted in multiples of 2
   //        Capacity of vector doubles when a new element is added beyond the capacity.
   //        On clearing the vector, size = 0, capacity remains unchanged


   // -------------------------------------------------------------------

   // // Accessing vector elements  : TC = O(1) .. in constant time

   // // Using array-type indices
   // vector<int> v1 = {1, 2, 4, 7, 16, 49};
   // cout << "v1[0] = " << v1[0] << endl;         // 1  

   // // using at()
   // cout << "v1.at(1) = " << v1.at(1) << endl;   // 2 

   // // accessing 1st element of a vector
   // cout<<"first element = "<<v1.front()<<endl;

   // // accessing last element of a vector
   // cout<<"last element = "<<v1.back()<<endl;                            
  
   // -------------------------------------------------------------------

   // // Accessing vector elements using for loops without iterators

   // // M1 : using indices
   // vector <int> v1 = {6,11,10,74,5};
   // for(int i=0; i<v1.size(); i++)
   // {
   //    cout<<v1[i]<<" ";
   // }
   // cout<<endl;


   // // M2 : using for-each loop range-based loop

   // // traversing a vector using for-each loop
   // for(int value : v1)
   // {
   //    cout<<value<<" ";      // Every element of vector v1 is copied sequentially into value , & then printed
   // }                         // Since a copy of each element is made ,changes made inside the loop won't reflect in the actual vector    
   // cout<<endl;               // similar to pass by value in a function




   // // using the auto keyword : automatically detects the datatype of the variable 
   // for(auto val : v1)      // for each loop : val is of <int> datatype
   // {
   //    cout<<val<<" ";
   // }
   // cout<<endl;


   // // Other functions

   // -------------------------------------------------------------------

   // // Copying vectors
   // vector<int> v3 = {9, 7, 6, 35};
   
   // // Deep cop
   // vector<int> v4 = v3;  // time O(n)
   // vector<int> v5(v3);  
   // printVec(v5); 
   
   // // Shallow copy
   // vector<int> &v6 = v3; // v5 is a reference to v3


   // -------------------------------------------------------------------
   // swapping 2 arrays
   vector<int> vt1 = {1,2,3,4};
   vector<int> vt2 = {5,6,7,8};
   vt1.swap(vt2);                   // swaps content of vt1 with vt2
   printVec(vt1);
   printVec(vt2);
   // -------------------------------------------------------------------
    
   // // clear / empty a vector 
   // vector <int> vt ={12,13,14};
   // vt.clear();                      // erases the entire vector

   // // check for an empty vector
   // cout<<vt.empty();                // returns 1 if vector is empty

   
   
   
   
   
   return 0;
}

/*

##############################################Extra Notes#####################################################

1. One benefit of using vectors, is that we can insert as many elements we want in a vector, without having to
   put some size parameter as in an array. In an array of 10 elements, for adding the 11th one, we’ll have to make
   an array again.

2. functions demonstrated : push_back()
                            pop_back()
                            size()
                            at()

3. insert (iterator, element to insert):
   This method of vectors inserts an element to the position the iterator is pointing to.
   We can generate an iterator using the scope resolution operator

4. Using begin () points the iterator to the starting of the vector.
   We can now increment the pointer according to our choice and insert any element at that position.

5. "v.at(i)" can be used instead of "v[i]". They will work the same.


*/