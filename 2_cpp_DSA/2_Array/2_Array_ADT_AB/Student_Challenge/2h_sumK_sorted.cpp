// Author : Yash Deshpande 
// Date : 16-06-2022
// Tutor : Abdul Bari

// Student Challenge : finding a pair of elements with sum K (sorted array)


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

void sumK (struct Array arr, int k)
{
    int i = 0;
    int j = arr.length - 1;
    while(i<j)
    {
        if(arr.A[i] + arr.A[j] == k)
        {
            cout<<arr.A[i]<<" + "<<arr.A[j]<<" = "<<k<<endl;
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j]  < k)
        {
            i++;
        }
        else if(arr.A[i] + arr.A[j] > k)
        {
            j--;
        }
    }

}

int main()
{
    struct Array arr1 = {{-3,-2, 2, 3, 3},20,5};
    display(arr1);  

    sumK(arr1, 0); 
    return 0;
}
/*

##############################################Extra Notes#####################################################


*/