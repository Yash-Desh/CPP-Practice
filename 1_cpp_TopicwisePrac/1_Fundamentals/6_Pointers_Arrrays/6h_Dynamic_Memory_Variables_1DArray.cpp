// Author : Yash Deshpande
// Date : 02-06-2022
// Tutor : Abdul Bari, Love Babbar 

#include <iostream>
using namespace std;

// function to return sum of array elements
int arrSum (int *arr, int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    cout<<"hello world"<<endl;

    // Dynamic Variables 
    int *ptr = new int;
    *ptr = 5;
    cout<<*ptr<<endl;

    // // deleting dynamic memory variable
    // delete ptr;


    // Dynamic Arrays

    // // Creating dynamic 1-D arrays inside heap using 'new'

    // int *ptr;
    // ptr = new int[5];

    // ptr[0]=12;
    // ptr[1]=34;
    // ptr[2]=54;
    // ptr[3]=4;
    // ptr[4]=66;

    // for(int j = 0; j<4; j++)
    // {
    //     cout<<ptr[j]<<endl;   // Pointer can act as the name of the array
    // }
    // cout<<endl;

    // deleting dynamic memory arrays
    // delete [] ptr;



    // // Creating "variable-sized" array in heap
    // int n;
    // cin>>n;
    // int *ptr = new int [n];

    // for(int i=0; i<n; i++)
    // {
    //     cin>>ptr[i];
    // }

    // // function to return sum of array elements
    // cout<<arrSum(ptr, n)<<endl;
    
    


    // // Concept : Heap memory is not freed automatically


    // // Case -1 : Not Dangerous
    // // Same variable is freed & recreated infinite times
    // // till time limit exceeds
    // // Program doesn't crash

    // while(true)
    // {
    //     int i = 5;
    // }

    // // Case -2 : Dangerous
    // // Different variable space is allocated
    // // infinite times until heap memory is full
    // // program crashes
    
    // while (true)
    // {
    //     int *ptr = new int;
    // }

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Dynamically allocated memory must be freed once we hv finished using it. This is of utmost importance if
   the program is large in size.

*/