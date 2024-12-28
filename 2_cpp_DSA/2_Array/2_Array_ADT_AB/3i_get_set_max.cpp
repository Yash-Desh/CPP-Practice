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


void display (struct Array a)
{
    cout<<"Displaying array elements : ";
    for(int j=0; j<a.length; j++)
    {
        cout<<a.A[j]<<" ";
    }
    cout<<endl;
}

// #1 get()
int get(struct Array arr, int index)   // struct passed by value since no modification is done on array values
{
    if(index>=0 && index < arr.length)   // condition to check validity of index 
    {
        return arr.A[index];
    }
    return -1;   // in case of an invalid index
}


// #2 set()
void set(struct Array *arr, int x, int index)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index] = x;
    }
}


// #3 max()
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


// #4 min()
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

// #5 sum()
int sum(struct Array arr)
{
    int total = 0;
    for(int i=0; i<arr.length; i++)
    {
        total = total + arr.A[i];
    }
    return total;
}


// #6 avg()
float avg (struct Array arr)
{
    return (float)sum(arr)/arr.length;  // result is typecasted to float 
}


int main()
{
    struct Array arr = {{1,2,3,4,17},20,5};
    display(arr);
    
    // using get()
    cout<<"get() : "<<get(arr,4)<<endl;

    // using set()
    set(&arr,15,3);
    display(arr);

    // using max()
    cout<<"maximum = "<<max(arr)<<endl;

    // using min()
    cout<<"minimum = "<<min(arr)<<endl;

    // using sum()
    cout<<"sum of elements = "<<sum(arr)<<endl;

    // using avg()
    cout<<"average of elements = "<<avg(arr)<<endl;

    
    return 0;
}