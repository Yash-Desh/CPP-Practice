// Author : Yash Deshpande
// Date : 09-08-2022
// Tutor : Abdul Bari , Luv

// NOTE : Range based loops , the for-each loop has been introduced only since C++ 11

#include <iostream>
using namespace std;

// function to print the numbers in an array
void print (int a[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    int arr[] = {12,5,77,43,9,34,65,23,85};
    cout<<"Given array : ";
    print(arr,9);

    // Add 2 to each element in the array
    for(int num : arr)          // pass by value
    {
        num += 2;
    }
    cout<<"After adding 2 to each element : ";
    print(arr, 9);
    


    // Add 5 to all numbers of the list 
    for(int &num : arr)         // pass by reference
    {
        num += 5;
    }
    cout<<"After adding 5 to each element : ";
    print(arr,9);
    


    return 0;
}