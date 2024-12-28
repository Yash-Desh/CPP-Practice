// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

int main()
{
    char A[] = "Painter";
    char B[] = "Paint";

    int i,j;
    for(i=0,j=0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if(A[i] != B[j])
        {
            break;
        }
    }
    if(A[i] == B[j])
    {
        cout<<"A & B are equal"<<endl;
    }
    else if(A[i] < B[j])
    {
        cout<<"A is lesser than B"<<endl;
    }
    else 
    {
        cout<<"A is larger than B"<<endl;
    }
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Above code is case sensitive 

2. To remove case-sensitivity , change both the strings to either lower/upper case & then compare.
*/ 