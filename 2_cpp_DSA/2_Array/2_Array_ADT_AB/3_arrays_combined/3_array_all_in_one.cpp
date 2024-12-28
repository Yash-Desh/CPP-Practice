// Author : Yash Deshpande 
// Date : 14-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

struct Array 
{
    int A[20];
    int size;     // Total elements in the array
    int length;   // Total values initialized in the array
};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// #1 Display()

void display (struct Array a)
{
    cout<<"Displaying array elements : ";
    for(int j=0; j<a.length; j++)
    {
        cout<<a.A[j]<<" ";
    }
    cout<<endl;
}


// #2 Append()
void append(struct Array *arr,int x)   // Call by address : modifies the array
{
    if(arr->length < arr->size)   // Condition : if array length < array size
    {
        arr->A[arr->length] = x;  // appends the array
        arr->length++;            // increments the array length
    }
}


// #3 Insert()
void insert(struct Array *arr, int index, int x)   // Call by address : modifies the array
{
   if(index >= 0 && index <= arr->length)          // Condition : if  index within range of array length 
   {
       for(int i = arr->length; i >index ; i--)
       {
           arr->A[i] = arr->A[i-1];       // Copies the element into the next location in the array
       }
       arr->A[index] = x;       // insert 
       arr->length++;           // increments the array length
   }
}


// #4 Delete()
int Delete(struct Array *arr, int index)     // Call by address : modifies the array
{
    int x = 0;  // set the return variable to 0
    int i;
    if(index>=0 && index < arr->length)  // Condition to check validity of given value of index
    {
        x = arr->A[index];   // copying the deleted element to be able to return
        for(i = index; i < arr->length-1; i++)    // length - 1 => loop to stop before reaching last index
        {
            arr->A[i] = arr->A[i+1];  // Elements shifted to remove empty space 
        }
        arr->length--;  // Length decremented
        return x;   // return the deleted element
    }
    return 0;  
}


// #5 Linear Search()
int LinearSearch (struct Array arr, int key)
{
    int i;
    for(i = 0; i<arr.length; i++)
    {
        if(key == arr.A[i])
        {
            return i;    // Current index returned if search successful
        }
    }
    return -1;  // Invalid index returned if search unsuccessful
}


// #6 Linear Search : Transposition

int LinearSearchT (struct Array *arr, int key)
{
    int i;
    for(i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}


// #7 Linear Search : Move to Head
int LinearSearchM (struct Array *arr, int key)
{
    int i;
    for(i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
}


// #8 Binary Search : Iterative Approach
int BinarySearch (struct Array arr, int key)
{
    int h,l,mid;
    h = arr.length - 1;    // Highest Index
    l = 0;     // Lowest Index
    while (h >= l)    // Condition to stop loop
    {
        mid = (h+l)/2;
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
    return -1;
}



// #9 Binary Search : Recursive Approach

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


// #10 get()
int get(struct Array arr, int index)   // struct passed by value since no modification is done on array values
{
    if(index>=0 && index < arr.length)   // condition to check validity of index 
    {
        return arr.A[index];
    }
    return -1;   // in case of an invalid index
}


// #11 set()
void set(struct Array *arr, int x, int index)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index] = x;
    }
}


// #12 max()
int max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}


// #13 min()
int min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// #14 sum()
int sum(struct Array arr)
{
    int total = 0;
    for(int i=0; i<arr.length; i++)
    {
        total = total + arr.A[i];
    }
    return total;
}


// #15 avg()
float avg (struct Array arr)
{
    return (float)sum(arr)/arr.length;
}



// #16 Reverse : Method 1 - Auxillary Array
void reverse(struct Array *arr)    // struct passed by address for modification
{
    int *B; 
    B = new int [arr->length];  // Auxillary array must be of the length of the given array
    
    int i,j;
    for(i=arr->length-1, j=0; i>=0; i--,j++) // Loop to copy elements in reverse order in auxillary array
    {
        B[j] = arr->A[i];
    }

    for(i=0; i<arr->length; i++)  // Loop to copy elements from auxillary array back into the original array
    {
        arr->A[i] = B[i];
    }
}


// #17 Reverse : Method 2 - Swap
void reverse2 (struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1; i<=j; i++,j--)  // swap() can be difined seperately & used 
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}



// #18 Left Shift
void left_shift (struct Array *arr)
{
    for(int i=0; i<arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = 0;
    // You can also the return the 1st element of the array
}


// #19 Left Rotate 
void left_rotate (struct Array *arr)
{
    int temp = arr->A[0];
    for(int i=0; i<arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    } 
    arr->A[arr->length-1] = temp;
}



// #20 Right shift
void right_shift (struct Array *arr)
{
    for(int i =arr->length-1; i>0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0;
    // The last element of the array can be returned 
}

// #21 Right Rotate
void right_rotate (struct Array *arr)
{
    int temp = arr->A[arr->length - 1];
    for(int i =arr->length-1; i>0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}



// #22 Insert an element in a sorted array 
void InsertSort (struct Array *arr, int x)
{
    int i = arr->length-1;
    if(arr->length == arr->size)  // condition to check whether the given array has space to accomodate a new element
    {
        return ;
    }
    while(i>=0 && x < arr->A[i])
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}




// #23 Check whether the given array is sorted in ascending
int isSorted(struct Array arr)
{
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}



// #24  Arrange all negative elements at left of an array
void rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if(i<j)  // Note : This extra if loop is very important to give accurate result
        {
           swap(&arr->A[i], &arr->A[j]);
        }
        
    }
}



// #25 merge (sorted arrays)
struct Array* merge(struct Array *ar1, struct Array *ar2)
{ 
    int i,j,k;
    i=j=k=0;
    struct Array *ar3 = new struct Array;
    while(i<ar1->length && j<ar2->length)
    {
        if(ar1->A[i] < ar2->A[j])
        {
            ar3->A[k++] = ar1->A[i++];
        }
        else
        {
            ar3->A[k++] = ar2->A[j++];
        }
    }
    for(;i<ar1->length; i++)
        {
            ar3->A[k++] = ar1->A[i];
        }

        for(;j<ar2->length; j++)
        {
            ar3->A[k++] = ar1->A[j];
        }
    ar3->length = ar1->length + ar2->length;
    ar3->size =10;
    return ar3;
}



// #26 Union of sorted arrays

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

// #27 Intersection of sorted arrays

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



// #28 Difference of 2 sorted arrays

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



// #29 Set Membership Operation
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











int main()
{
    struct Array arr1 = {{2,34,4,5,15,7},20,5};
    display(arr1);   
    return 0;
}