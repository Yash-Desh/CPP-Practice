// Author : Yash Deshpande
// Date : 20-03-2022

#include <iostream>
using namespace std;

int main()
{

    // Understanding the null character '\0'

    char arr[100] = "apple juice";   // character arrays are of length n+1 , 1 greater for the null character '\0'
    int i = 0;
    
    while(arr[i] != '\0')
    {
        cout<<arr[i]<<endl;
        i++;
    }

    // Taking input & giving output 

    char arr1 [100];
    cin>>arr1;

    cout<<arr1;

    return 0;
}