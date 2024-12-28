// Author : Yash Deshpande 
// Date : 13-04-2022
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

int main()
{
    struct Array arr = {{1,2,3,4,17},20,5};
    display(arr);   
    return 0;
}
/*

##############################################Extra Notes#####################################################


*/
