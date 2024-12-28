// Author : Yash Deshpande 
// Date : 19-04-2022
// Tutor : Abdul Bari


/*

Methods to perform Binary Search Operation on a "SORTED" array
    1. Iterative Approach
    2. Recursive Approach (Tail Recursion)

*/


#include <iostream>
using namespace std;

struct Array 
{
    int A[20];
    int size;     // Total elements in the array
    int length;   // Total values initialized in the array
};


void display (struct Array a)
{
    cout<<"Displaying array elements : ";
    for(int j=0; j<a.length; j++)
    {
        cout<<a.A[j]<<" ";
    }
    cout<<endl;
}

// Binary Search : Iterative Approach
    int BinarySearch (struct Array arr, int key)
    {
        int h,l,mid;
        h = arr.length - 1;    // Highest Index
        l = 0;     // Lowest Index
        while (h >= l)    // Condition to stop loop
        {
            mid = (h+l)/2;  
            // NOTE : what if h & l are both the largest possible
            //        integers ?
            // Adding 2 of such numbers will result in overflow 
            // since int cannot handle numbers larger than 2^31 - 1 
            // To handle this situation we can write 
            //   " mid = l + (h-l)/2 "
            // to prevent overflow of integer values

            if(key == arr.A[mid])
            {
                return mid;
            }
            else if(key < arr.A[mid])
            {
                h = mid - 1;
            }
            else 
            {
                l = mid + 1;
            }
        }
        return -1;   // return -1 only when the while is over 
    }



// Binary Search : Recursive Approach

int RBinSearch (int a[],int l, int h, int key)  // An array given as a parameter
{
    int mid;

    if (l <= h)
    {
        mid = (l+h)/2;
        if(key == a[mid])
        {
            return mid;
        }
        else if (key <= a[mid])
        {
            return RBinSearch(a,l,mid-1,key);
        }
        else
        {
            return RBinSearch(a, mid+1, h, key);
        }
    }
    return -1;
}



int main()
{
    struct Array my_arr = {{2,3,9,16,18,21,28,32,35},10,9};;

    cout<<BinarySearch(my_arr, 4)<<endl;

    cout<<RBinSearch(my_arr.A,0, my_arr.length-1,4)<<endl;
    display(my_arr);   
    return 0;
}