// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Q. To reverse a string using a seperate array (Method-1)

#include <iostream>
using namespace std;

int main()
{
    char A[] = "mercedes";
    char B[9];

    int i, j;
    for(i = 0; A[i] != '\0'; i++)
    {
        // Do Nothing
    }
    i = i-1;
    for(j=0; i>=0; i--,j++)
    {
        B[j]=A[i];
    }
    B[j] = '\0';   // Convert character array to string 
    cout<<B<<endl;
    return 0;
}