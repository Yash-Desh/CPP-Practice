// Author : Yash Deshpande
// Date : 20-03-2022

// Q. Check Palindrome

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    char arr[n+1];
    cin>>arr;

    bool check = 1;

    for(int i = 0; i<n; i++)
    {
        if(arr[i] != arr[n-1-i])
        {
            check = 0;
        }
    }

    if (check == 1){
        cout<<"palindrome";
    }
    else{
        cout<<"Not palindrome";
    }
    return 0;
}