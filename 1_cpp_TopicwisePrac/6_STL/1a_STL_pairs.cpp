// Author : Yash Deshpande
// Date : 4-08-2022
// Tutor : Luv & Striver

#include <iostream>
using namespace std;

int main()
{
    // // Declaring a pair 
    // pair <int , string> p1;

    // // Initializing a pair
    // p1 = make_pair(3,"hello");

    // p1 = {2, "abcd"};


    // // Accessing pair elements 
    // cout<<"1st element in the pair is "<<p1.first<<endl;
    // cout<<"2nd element in the pair is "<<p1.second<<endl;


    // // Copying pairs 

    // // deep copy 
    // pair <int , string> p2 = p1;     // changes made to p2 will not reflect in p1

    // // shallow copy 
    // pair <int , string> &p3 = p1;    // p3 is a reference variable to p1

    
    // // Array of pairs 
    // int a[] = {1,2,3};   // int array hving 3 values
    // int b[] = {7,8,9};   // int array hving 3 values

    // pair <int, int> p_array [3];
    // p_array[0] = {1,7};
    // p_array[1] = {2,8};
    // p_array[2] = {3,9};

    // // p_array[] = {{1,7},{2,8},{3,9}};     --> another array declaration
    
    // // Displaying array of pairs
    // for(int i=0; i<3; i++)
    // {
    //     cout<<p_array[i].first<<" is related to "<<p_array[i].second<<endl;
    // }

    
    // // Nested Pairs
    // pair<int, pair<int,int>> p4 = {3,{4,7}};

    // cout<<"1st = "<<p4.first<<"  \n2nd = "<<p4.second.first<<"  \n3rd = "<<p4.second.second<<endl;

    // Comparison between pairs 
    pair <int ,int > pr1 , pr2;
    pr1 = {1,7};
    pr2 = {3,4};
    cout<<(pr1<pr2)<<endl;      // 1

    // NOTE : comparison b/w 2 pairs with comparison operator
    //        compares the "first" of both pairs
    //        returns 1 if true , 0 if false
    //        if "first" of both pairs same , then compares the "second" of both pairs
    

    return 0;
}