// Author : Yash Deshpande
// Date : 01-09-2022
// Tutor : Love Babbar Complete Placement Course

#include <bits/stdc++.h>
using namespace std;


// function to Linear Search in a 2D array
// Provide the function with dimensions of the array as parameters
// Why to provide column-size when passing
// 2-D array as parameter ?
// TC : O(N^2)
bool isPresent (int key, int arr[][4], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(arr[i][j] == key)
            {
                return 1;
            }
        }
    }
    return 0;
}


// function to print Row-wise sum
void printSumRowWise (int arr[][3], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        int sum=0;
        for(int j=0; j<col; j++)
        {
            sum+=arr[i][j];
        }
        cout<<"Sum of row "<<i<<" = "<<sum<<endl;
    }
    cout<<endl;
}


// function to print Column-wise sum
void printSumColWise (int arr[][3], int row, int col)
{
    for(int j=0; j<col; j++)
    {
        int sum=0;
        for(int i=0; i<row; i++)
        {
            sum+=arr[i][j];
        }
        cout<<"Sum of column "<<j<<" = "<<sum<<endl;
    }
    cout<<endl;
}


// function to return the largest row sum
int LargestRowSum (int arr[][3], int row, int col)
{
    int rowIndex=-1;
    int maxSum = INT_MIN;
    for(int i=0; i<row; i++)
    {
        int currentSum=0;
        for(int j=0; j<col; j++)
        {
            currentSum += arr[i][j];
        }
        
        if(currentSum > maxSum)
        {
            maxSum = currentSum;
            rowIndex = i;
        }
    }
    cout<<"Largest Row Sum = "<<maxSum<<endl;
    return rowIndex;
}



int main()
{
    // Declaring & Initializing 2D Arrays
    // int arr2D [3][4];

    // // Taking Input : Row-Wise Input
    // for(int row=0; row<3; row++)
    // {
    //     for(int col=0; col<4; col++)
    //     {
    //         cin>>arr2D[row][col];
    //     }
    // }


    // // Taking Input : Column-Wise Input
    // for(int col=0; col<4; col++)
    // {
    //     for(int row=0; row<3; row++)
    //     {
    //         cin>>arr2D[row][col];
    //     }
    // }


    // Hard-coding a 2D array
    
    // Default behavior is row-matrix 
    int arr2D[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    // Creating a column-matrix hard-coded 2D array
    // int arr2D [3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};


    // // Displaying a 2D matrix
    for(int row=0; row<3;  row++)
    {
        for(int col=0; col<4; col++)
        {
            cout<<arr2D[row][col]<<" ";
        }
        cout<<endl;
    }



    // // Linear Search in a 2D array
    // int arr2D[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // cout<<"Enter Element : ";
    // int value;
    // cin>>value;
    // if(isPresent(value, arr2D, 3,4))
    // {
    //     cout<<"Found"<<endl;
    // }
    // else
    // {
    //     cout<<"Not Found"<<endl;
    // }



    // // Row-Wise / Column-wise Sum of Elements
    // int arr2D[3][3] = {{7,5,6},{11,5,3},{14,8,2}};
    // printSumRowWise (arr2D, 3,3);
    // printSumColWise (arr2D, 3, 3);


    // Largest Row Sum 
    // int arr2D[3][3] = {{7,5,6},{11,5,3},{14,8,2}};
    // cout<<LargestRowSum(arr2D, 3,3)<<endl;

    return 0;
}