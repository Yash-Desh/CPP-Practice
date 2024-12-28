// Author : Yash Deshpande
// Date : 13-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

// Method - 1 : Sort the array using std::sort()
// TC : O(N * LogN)

// Method : 
// 2-Pointer Approach

struct Array
{
    int A[20];
    int size;   // Total elements in the array
    int length; // Total values initialized in the array
};

void display(struct Array a)
{
    cout << "Displaying array elements : ";
    for (int j = 0; j < a.length; j++)
    {
        cout << a.A[j] << " ";
    }
    cout << endl;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0 && i<arr->length)
        {
            i++;
        }
        while (arr->A[j] >= 0 && j >= 0)
        {
            j--;
        }
        if(i<j)  // Note : This extra if condition is very important to give accurate result
        {
           swap(&arr->A[i], &arr->A[j]);
        }
        
    }
}

int main()
{
    struct Array my_arr = {{25,44,-61, 2, -31, 4, -17}, 20, 7};
    display(my_arr);

    rearrange(&my_arr);
    display(my_arr);

    return 0;
}