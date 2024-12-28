// Author : Yash Deshpande
// Date : 15-06-2022
// Tutor : Abdul Bari

/*

Set Operations (on sorted arrays)
    1. Union
    2. Intersection
    3. Difference

*/

#include <iostream>
using namespace std;

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

// Union of sorted arrays

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];

        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// Intersection of sorted arrays

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}



// Difference of 2 sorted arrays

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            j++;

        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// Set membership operation == Binary Search (for sorted arrays)
int SetMember (struct Array arr, int key)
{
    int h,l;
    l=0;
    h=arr.length - 1;
    while (h>=l)
    {
        int mid = (h+l)/2;
        if(arr.A[mid] == key)
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            h = mid - 1;
        }
        else // if (key > arr.A[mid)
        {
            l = mid + 1;
        }
    }
    return -1;  // for unsuccessful search
}


// Operations on unsorted arrays
int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 25}, 20, 5};
    struct Array arr2 = {{3, 6, 7, 15, 20}, 20, 5};

    struct Array *arr3;
    arr3 = Difference(&arr1, &arr2);
    display(*arr3);   // // Dereferencing the pointer arr3 for call by value

    return 0;
}