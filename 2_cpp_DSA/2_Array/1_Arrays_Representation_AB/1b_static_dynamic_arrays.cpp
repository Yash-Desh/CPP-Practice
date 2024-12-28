// Author : Yash Deshpande 
// Date : 12-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

int main()
{
    // Static Array
    int A[5] = {2,4,6,8,10};


    // Dynamic Array
    int *p;
    p = new int [5];
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;
    

    // Displaying elements

    for(int i = 0; i<5; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i<5; i++)
    {
        cout<<p[i]<<" ";
    }
    return 0;
}