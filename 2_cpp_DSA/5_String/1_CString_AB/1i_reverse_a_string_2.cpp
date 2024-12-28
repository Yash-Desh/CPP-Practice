// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Q. To reverse a string by swap method (Method-2)

#include <iostream>
using namespace std;

int main()
{
    char A[] = "RedBull";
    int i, j;
    for(j=0; A[j] != '\0'; j++)
    {
        // Do Nothing
    }
    j=j-1;
    for(i=0; i<j; i++,j--)
    {
        char temp;
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    cout<<A;
    return 0;
}

