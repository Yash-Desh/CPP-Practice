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

// Insert an element in a sorted array 
void InsertSort (struct Array *arr, int x)
{
    int i = arr->length-1;
    if(arr->length == arr->size)  // condition to check whether the given array has free space to accomodate a new element
    {
        return;   // return statement when the return type is void
    }
    while(i>=0 && x < arr->A[i])
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int main()
{
    struct Array my_arr = {{2,3,5,10,15},20,5};
    display(my_arr);  

    cout<<"After InsertSort"<<endl;
    InsertSort(&my_arr,12); 
    display(my_arr);


    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Using return statement in void return type function:
        1. think of it as an alternative to “break statement” to use in functions.
        2. This syntax is used in function just as a jump statement in order to break the flow of the function and 
           jump out of it.
        3. Syntax :
                    void func()
                    {
                        return;
                    }   

        


*/ 