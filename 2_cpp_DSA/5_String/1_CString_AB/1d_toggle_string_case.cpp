// Author : Yash Deshpande
// Date : 16-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

int main()
{
    char A[] = "W5elCoMe";
    for(int i=0; A[i] != '\0'; i++)
    {
        if(A[i]>=65 && A[i]<=90)
        {
            A[i] += 32;
        }
        else if(A[i]>=97 && A[i]<=122)
        {
            A[i] -= 32;
        }
    }
    cout<<A<<endl;

    return 0;
}
/*

##############################################Extra Notes#####################################################

1. The characters apart from alphabets remain unchanged

2. 32 is the difference in the ASCII code to inter-convert between uppercase & lowercase


*/