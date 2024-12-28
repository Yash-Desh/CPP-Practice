// Author : Yash Deshpande
// Date : 16-06-2022
// Tutor : Abdul Bari

// To change the uppercase string to lower case

#include <iostream>
using namespace std;

int main()
{
    char A[] = "WELCOME";
    for(int i = 0; A[i] != '\0'; i++)
    {
        A[i] += 32;  // ASCII difference between uppercase & lowercase letters is 32
    }
    cout<<A<<endl;
    return 0;
}

// NOTE : By subtracting 32 lowercase letters can be converted to uppercase letters