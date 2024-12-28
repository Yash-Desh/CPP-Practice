// Author : Yash Deshpande
// Date : 10-02-2022

#include <iostream>
using namespace std;

int main()
{
    // Basic Example of Pointers
    int a = 4;
    int* ptr = &a;
    cout<<"The value of a is "<<*(ptr)<<endl;

    // new operator
    
    float *p = new float(40.78);
    cout << "The value at address p is " << *(p) << endl;

    int *arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;

    
    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. Pointers are variables that are used to store the address. 

2. Pointers are created using “*”.

3. 'new' keyword is used to dynamically created an int, float, array etc.  

4. By using delete keyword the space used by an array gets free.

*/