// Author : Yash Deshpande 
// Date : 19-04-2022
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

// delete
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

int main()
{
    struct Array my_arr = {{1,2,3,4,17},20,5};
    display(my_arr);

    // delete
    int val = Delete(&my_arr,2);
    cout<<val<<endl;
    display(my_arr);   
    return 0;
}