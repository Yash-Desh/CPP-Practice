// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Q. To check for palindrome using swap method(Method-2)

#include <iostream>
using namespace std;

int main()
{
    char A[] = "liril";
    int i, j;
    for(j=0; A[j] != '\0'; j++)
    {
        // Do Nothing
    }
    j=j-1;
    for(i=0; i<j; i++,j--)
    {
        if(A[i] != A[j])
        {
            cout<<"Not a Palindrome"<<endl;
            return 0;
        }
    }
    cout<<"Palindrome"<<endl;
    return 0;
}