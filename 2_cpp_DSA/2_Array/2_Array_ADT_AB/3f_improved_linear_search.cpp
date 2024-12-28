// Author : Yash Deshpande 
// Date : 19-04-2022
// Tutor : Abdul Bari


/*

Methods to improve Linear Search
    1. Transposition (T)
    2. Move to Head (M)

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


// swap

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Transposition

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


// Move to Head
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

int main()
{
    struct Array arr = {{1,2,3,4,17},20,5};
    display(arr);

    int key_index1 = LinearSearchT(&arr, 1);
    cout<<"Index of key "<<key_index1<<endl;  
    display(arr);

    int key_index2 = LinearSearchM(&arr, 17);
    cout<<"Index of key "<<key_index2<<endl;  
    display(arr);

    return 0;
}

/*

##############################################Extra Notes#####################################################

Transposition

1. If the element is found at the 1st location , swap() function must not be called and  'i' must be returned.

2. In the code written here no safegaurd is taken for this case


Move to head 

1. If the element is found at the first place a swap() function must not be called.

2. No safegaurd taken for this case , in the above code.

*/