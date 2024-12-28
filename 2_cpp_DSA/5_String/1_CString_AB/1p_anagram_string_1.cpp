// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Q. To find whether the given strings are anagram

// Method -1 : Linear search method

#include <iostream>
using namespace std;

int main()
{
    char A[] = "decimal";
    char B[] = "medical";

    int i,j;
    for(i=0; A[i] != '\0'; i++)
    {
        bool flag =0;
        for(j=0; B[j]!='\0'; j++)
        {
            if(A[i]==B[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag != 1)
        {
            cout<<"Not Anagram"<<endl;
            return 0;
        }
    }
    cout<<"Anagram"<<endl;

    return 0;
}