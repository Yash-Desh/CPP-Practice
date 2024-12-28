// Author : Yash Deshpande 
// Date : 12-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

int main()
{
    // Methods of Array declaration
    int A[5];
    int B[5] = {1,2,3};
    int C[5] = {0};
    int D[5] = {1,2,3,4,5};
    int E[] = {2,4,6,8,10};

    // Determining memory locations of array elements

    for(int i = 0; i <5; i++)
    {
        cout<<&A[i]<<endl;
    }


    // Accessing array elements
    cout<<B[2]<<endl;
    cout<<2[B]<<endl;
    cout<<*(B+2)<<endl;
    return 0;
}