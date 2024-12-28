// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Q. To find the duplicates within a string using bitwise operations(Method-3)

// NOTE : This  program is only for lowercase letters

#include <iostream>
using namespace std;

int main()
{
    char A[] = "finding";
    int H=0, x=0;  // H = 4 byte hash table, X = variable to perform bitwise operations with H

    for(int i=0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i]-97);   // left shift 
        if((H & x)>0)   // masking
        {
            cout<<A[i]<<" is duplicated "<<endl;
        }
        else
        {
            H = H | x;  // merging
        }
    }
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Bitwise Operations performed are
        AND
        OR
        Left shift

*/