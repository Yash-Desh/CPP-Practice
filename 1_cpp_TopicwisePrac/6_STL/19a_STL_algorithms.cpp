// Author : Yash Deshpande
// Date : 11-08-2022
// Tutor : CodeWithHarry , Luv , Striver, Love Babbar

/*
There are some in-built algorithms inside STL
All of these algos have a common feature , that is the indexes / iterators 
they accept 
They take the starting index & the index next to the last index we want to work on
Time = O(n) for vectors & arrays

all_of(), any_of(), none_of() , these functions return bool values

*/

#include <bits/stdc++.h>
using namespace std;


// function to display vector elements
void displayVector (vector <int> vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    // // vector 
    // int n;
    // cin>>n;
    // vector <int> v(n);
    // for(int i=0; i<n; i++)
    // {
    //     cin>>v[i];
    // }

    // // min_element() 
    // // returns pointer / iterator to the minimum element in the array / vector
    // int min = *min_element(v.begin(), v.end());
    // cout<<min<<endl;


    // // max_element() 
    // // returns pointer / iterator to the maximum element in the array / vector
    // int max = *max_element(v.begin()+2, v.end());
    // cout<<max<<endl;


    // // accumulate()
    // // returns the cumulative sum of all elements from the starting index till the ending index
    // int sum = accumulate(v.begin(), v.end(),0);   // 3rd parameter here is initial sum =0 here
    // cout<<sum<<endl;


    // // count()
    // // returns the count of number of times an element is repeated in the ds
    // int cnt = count(v.begin(), v.end(), 16);
    // cout<<cnt<<" of 16"<<endl;


    // //find()
    // // returns the pointer / iterator to the location of the desired element
    // // returns the pointer to the next location of the last index under consideration 
    // // when the element is not found
    // int element = *find(v.begin(), v.end(), 55);
    // cout<<element<<endl;


    // // reverse()
    // // reverses a ds
    // // very useful in case of strings, arrays , vectors
    // reverse(v.begin(), v.end());
    // for(int n : v)
    // {
    //     cout<<n<<" ";
    // } 
    // cout<<endl;


    // similarly, these functions can be shown for vectors

    // NOTE : v.end() for vectors points to location after last index
    // similarly for arrays, its arr+n that points to location after last index 


    // // Binary Search
    
    // vector <int> v1 = {1,3,5,12,54,98};
    // // Returns 0(false) or 1(true)
    // cout<<"Finding 6 in the vector v1 -> "<<binary_search(v1.begin(), v1.end(), 6)<<endl;

    
    // Rotate

    vector <int> v2 = {1,3,6,7};
    displayVector(v2);


    rotate(v2.begin(), v2.begin()+2, v2.end());
    displayVector(v2);
    
    
    // some other slightly unheard of algos





    return 0;
}