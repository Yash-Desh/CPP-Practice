// Author : Yash Deshpande
// Date : 08-06-2022
// Tutor : Love Babbar L-29  

// Creating 2-D Arrays 
// Dynamically in heap memory

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Creating a 2-D dynamic Array of size row*col
    int row, col;
    cin>>row>>col;
    
    int **arr2D = new int *[row];
    for(int i=0; i<row; i++)
    {
        arr2D[i] = new int [col];
    }


    // Taking input in a 2D dynamic Array
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>arr2D[i][j];
        }
    }


    // Printing a 2d dynamic array
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<arr2D[i][j]<<" ";
        }
        cout<<endl;
    }

    // Releasing memory of a 2D dynamic array
    
    // step-1
    for(int i=0; i<row; i++)
    {
        delete [] arr2D[i];
    }
    // step-2
    delete []arr2D;




    return 0;
}