// Author : Yash Deshpande
// Date : 31-01-2023

#include <bits/stdc++.h>
using namespace std;

void print(int n, string *arr)
{
    if(n == 0)
        return;

    int digit = n%10;
    print(n/10, arr);
    cout<<arr[digit]<<" ";
}

int main()
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    print(967, arr);
    return 0;
}