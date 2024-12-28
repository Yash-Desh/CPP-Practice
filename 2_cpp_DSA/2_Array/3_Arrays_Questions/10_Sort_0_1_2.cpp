// Author : Yash Deshpande
// Date : 19-08-2022
// Website : Coding Ninjas
// Tutor : Love Babbar Placement series
// Topic : Arrays

// Also known as the dutch national flag(DNF) problem

#include <iostream>
using namespace std;

// Approach -1 : Count the number of 0s, 1s & 2s

// Approach -2 : Traverse & add to vector
// if u find 2 append it to array
// if u find 0 insert at beginning
// if u find 1 insert at beginninng+number of zeros

// Approach -3 : Using in-built sort

// Approach 4 : Using 3 pointer algo "DNF algo"
void sort012(int *arr, int n)
{
    //   Write your code here
    int low = 0, mid = 0, high = n - 1;
    // why mid <= high & why not mid < high ?
    // when mid == high the unknown region 
    // doesnt exist any more
    // the condition to stop loop is when
    // unknown region doesn't exist 
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[mid++], arr[low++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
}


void sort012(int *arr, int n)
{
   //   Write your code here
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
}

int main()
{

    return 0;
}