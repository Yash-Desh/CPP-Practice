// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Method - 1 : To check palindrome by using another array(Method-1)

#include <iostream>
using namespace std;

int main()
{
    char A[] = "nitin35";
    char B[6];


    // Step - 1 : To reverse copy a string 
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
    B[j] = '\0';

    // Step - 2 : To compare the 2 strings 
    
    for(i=0,j=0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if(A[i] != B[j])
        {
            break;
        }
    }
    if(A[i] == B[j])
    {
        cout<<"Palindrome"<<endl;
    }
    else 
    {
        cout<<"Not a Palindrome"<<endl;
    }


    return 0;
}