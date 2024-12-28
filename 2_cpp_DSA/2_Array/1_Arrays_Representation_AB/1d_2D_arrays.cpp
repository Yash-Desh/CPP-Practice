// Author : Yash Deshpande 
// Date : 12-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

int main()
{
    // M1
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};

    // M2
    int *B[3];
    B[0] = new int [4];
    B[1] = new int [4];
    B[2] = new int [4];

    //M3
    int **C;
    C = new int* [3];
    C[0] = new int [4];
    C[1] = new int [4];
    C[2] = new int [4];

    // Displaying 2D array elements using for loops
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    // Note : 2D Array representation Quiz

    int x[4] [3] ={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    // Methods to print array values 
    cout<<"x[1][2] = "<<x[1][2]<<endl;  // prints x[1][2]
    cout<<"*(*(x+1)+2) = "<<*(*(x+1)+2)<<endl;  // prints x[1][2]
    
    // Methods to print address
    cout<<"*(x+1)+2 = "<<*(x+1)+2<<endl;  // prints address of x[1][2]
    cout<<"*(x+1) = "<<*(x+1)<<endl;  // prints address of x[1][0]
    cout<<"x+1 = "<<x+1<<endl;  // prints address of x[1][0]

    return 0;
}