// Author : Yash Deshpande
// Date : 4-08-2022
// Tutor : CodeWithHarry , Luv , Striver

#include <bits/stdc++.h>
using namespace std;


// Note : Accessing out of bound elements in vectors will lead
// to segmentation faults 



// Simple function to print vector elements
void printVec (vector <int> V)    // <data_type> change datatype as per need to print
{
   for(int i=0; i<V.size(); i++)
   {
      cout<<V[i]<<" ";
   }
   cout<<endl;
}


// function to print a vector of pairs
void printVecPair (vector <pair<int,int>> vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i].first<<" , "<<vec[i].second<<endl;
    }
}


// function to print array vectors 
void printVecArr (vector <int> vec[] ,int n)    // n = size of the array
{
    for(int i=0; i<n; i++)
    {
        printVec(vec[i]);
    }
}


// function to print vector of vectors 
void printVecVec (vector <vector<int>> vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        printVec(vec[i]);
    }
}

int main()
{
    // // Vector of Pairs

    // // Declaring a vector of pairs
    // vector <pair<int,int>> v1;

    // v1.push_back({25,67});        // {} necessary
    // v1.emplace_back(13,12);       // {} not necessary

    // // Declaring & initializing at the same time
    // vector <pair<int,int>> v2 = {{1,2},{3,4},{5,6}};
    // printVecPair (v2);


    // // Array of vectors
    // vector <int> v3[5];   // empty array of vectors of size 5

    // // Taking input in Array of vectors
    // for(int i=0; i<5; i++)
    // {
    //     int m;     // number of elements , to be entered in the vector
    //     cout<<"Enter number of elements in vector v2["<<i<<"] : ";
    //     cin>>m;
    //     for(int j=0; j<m; j++)
    //     {
    //         int val;
    //         cin>>val;
    //         v3[i].push_back(val);
    //     }
    // }
    // printVecArr(v3, 5);


    // Vector of vectors

    // vector <vector<int>> v4;
    // int N=3;

    // // Taking input for vector of vectors
    // for(int i=0; i<N; i++)
    // {
    //     // creating a new temporary vector & filling it with m values
    //     vector <int> temp;
    //     int m;
    //     cout<<"Enter number of elements in vector :";
    //     cin>>m;
    //     for(int j=0; j<m; j++)
    //     {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }

    //     // Append the newly created vector to main vector v4
    //     v4.push_back(temp);

    //     // NOTE : you may also append an empty temp vector to the main vector , & then push_back elements to it
    // }
    // printVecVec(v4);

    // // Accessing individual elements in a vector of vectors 
    // cout<<endl<<endl<<v4[0][1]<<endl;


    // ############################
    // Nvidia Interview Question
    // ############################
    vector<vector<int>> myVec = {{1, 2, 3}, 
                                 {4, 5, 6}, 
                                 {7, 8, 9}};

    for(int i=0; i<myVec.size(); i++) {
        for(int j=0; j<myVec[i].size(); j++) {
            cout<< &myVec[i][j] <<" ";
        }
        cout<<endl;
    }

    return 0;
}