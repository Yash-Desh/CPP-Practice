// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Q. To find whether the given strings are anagram (can handle duplicate elements)

// Method-2 : Using hash table

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char A[] = "sadder";
    char B[] = "sad";

    int H[26] = {0};
    int i;

    // if (A.length() != B.length())
    // {
    //     cout << "not anagram" << endl;
    // }

    // else
    // {
        for (i = 0; A[i] != '\0'; i++)
        {
            H[A[i] - 97]++;
        }

        for (i = 0; B[i] != '\0'; i++)
        {
            H[B[i] - 97]--;
            if (H[B[i] - 97] < 0)
            {
                cout << "not anagram" << endl;
                break;
            }
        }
        if (B[i] == '\0')
        {
            cout << "anagram" << endl;
        }
    // }

    return 0;
}