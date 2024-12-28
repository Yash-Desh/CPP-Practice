// Author : Yash Deshpande
// Date : 20-03-2022

// Q. Find the largest word in a sentence

#include <iostream>
using namespace std;

int main()
{
    char sentence[100];
    cin>>sentence;

    int max = 0;
    int num = 0 ;
    int i = 0;
    while (sentence[i] != '\0')
    {
        if(sentence[i] != ' ')
        {
            num++;
        }
        else{
            if(num >= max)
            {
                max = num;
            }
        }
    }
    return 0;
}