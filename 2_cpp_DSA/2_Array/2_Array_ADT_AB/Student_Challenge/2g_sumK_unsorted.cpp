// Author : Yash Deshpande 
// Date : 16-06-2022
// Tutor : Abdul Bari

// Student Challenge : finding a pair of elements with sum K (unsorted array)

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


// Method -1 : without hashing

void sumK (struct Array arr, int k)
{
    for(int i=0; i<arr.length-1; i++)
    {
        for(int j=i+1; j<arr.length; j++)
        {
            if(arr.A[i]+arr.A[j] == k)
            {
                cout<<arr.A[i]<<" + "<<arr.A[j]<<" = "<<k<<endl;
            }
        }
    }
}

// Method - 2 : using hashing
void sumK_hash(struct Array arr, int k)
{
    int h = max(arr);
    int H[h + 1] = {0};
    
    for(int i = 0 ; i<arr.length; i++)
    {
        if(H[k-arr.A[i]] == 1 )
        {
            cout<<arr.A[i]<<" + "<<k-arr.A[i]<<" = "<<k<<endl;
        }
        H[arr.A[i]]++;
    }
}

int main()
{
    struct Array arr1 = {{6,3,8,10,16,7,5,2,9,14},20,10};
    display(arr1);   

    sumK_hash(arr1, 13);
    return 0;
}
/*

##############################################Extra Notes#####################################################


*/