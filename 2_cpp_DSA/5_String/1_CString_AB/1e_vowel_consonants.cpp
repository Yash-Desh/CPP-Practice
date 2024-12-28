// Author : Yash Deshpande
// Date : 16-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

int main()
{
    char A[] = "how are you";
    int vCount =0, cCount =0;  // vCount = number of vowels  ,  cCount = number of consonants
    for(int i = 0; A[i] != '\0'; i++)
    {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
        {
            vCount++;
        }
        else if((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122))
        {
            cCount++;
        }
    }
    cout<<"Number of vowels = "<<vCount<<"\nNumber of consonants = "<<cCount<<endl;
    return 0;
}