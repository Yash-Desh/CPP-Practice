// Author : Yash Deshpande 
// Date : 16-06-2022
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

void minMax (struct Array arr)
{
    int min = arr.A[0];
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i]<min)
        {
            min = arr.A[i];
        }
        else if (arr.A[i] > max)
        {
            max = arr.A[i];
        } 
    }
    cout<<"max = "<<max<<"\nmin = "<<min<<endl;
}

int main()
{
    struct Array arr1 = {{5,8,3,9,6,2,10,7,-1,4},20,10};
    display(arr1); 
    
    minMax(arr1);
    return 0;
}
/*

##############################################Extra Notes#####################################################


*/