// Author : Yash Deshpande
// Date : 27-07-2023
// Tutor : 450 DSA

#include <iostream>
using namespace std;

// Abdul Bari Method
// AC
// TC : O(N)
// SC : O(1)
void rotate(int arr[], int n)
{
    int x = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = x;
}

int main()
{

    return 0;
}