// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Q. To find the duplicates within a string using hash table(Method-2)

// NOTE : This  program is only for lowercase letters

#include <iostream>
using namespace std;

int main()
{
    char A[] = "finding";
    int H[26] ={0}; // Because there are 26 alphabets

    for(int i=0; A[i] != '\0'; i++)
    {
        H[A[i]-97]++;
    }

    for(int i=0; i<26; i++)
    {
        if(H[i]>1)
        {
            cout<<char(i+97)<<" is duplicated "<<H[i]<<" times"<<endl;
        }
    }
    return 0;
}