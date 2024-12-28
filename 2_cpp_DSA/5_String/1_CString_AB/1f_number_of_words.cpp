// Author : Yash Deshpande
// Date : 16-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

int main()
{
    char A1[]= "how are you";
    int word1 =1;                       // // Notice that the word count starts from one
    for(int i=0; A1[i] != '\0'; i++)
    {
        if(A1[i] == ' ')
        {
            word1++;
        }
    }
    cout<<"Number of words "<<word1<<endl;


    // With white spaces
    char A2[]= "how are   u";
    int word2 =1;                       // Notice that the word count starts from one 
    for(int i=0; A2[i] != '\0'; i++)
    {
        if(A2[i] == ' ' && A2[i-1] != ' ' )
        {
            word2++;
        }
    }
    cout<<"Number of words "<<word2<<endl;



    return 0;
}