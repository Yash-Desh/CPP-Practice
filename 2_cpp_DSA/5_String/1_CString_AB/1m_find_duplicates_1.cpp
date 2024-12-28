// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Q. To find duplicates in a string (method-1)

#include <iostream>
using namespace std;

int main()
{
    char A[] = "finding";
    int i, j;
    for(i=0;A[i] != '\0'; i++)
    {
        int count = 1;
        for(j=i+1; A[j] != '\0'; j++)
        {
            if(A[i] == A[j])
            {
                count++;
            }
        }
        if(count>1)
        {
            cout<<A[i]<<" is duplicated "<<count<<" times"<<endl;
        }
    }
    return 0;
}