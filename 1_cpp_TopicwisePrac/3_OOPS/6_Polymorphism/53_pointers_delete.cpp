// Author : Yash Deshpande
// Date : 21-02-2022

#include <iostream>
using namespace std;

int main()
{
    // delete operator

    int *arr1 = new int[3];
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;

    // delete arr1;  --> Note the difference between delete & delete[]
    delete[] arr1;
    cout << "The value of arr[0] is " << arr1[0] << endl;
    cout << "The value of arr[1] is " << arr1[1] << endl;
    cout << "The value of arr[2] is " << arr1[2] << endl;


    return 0;
}
/*

##############################################Extra Notes#####################################################s

1. By using delete keyword the space used by an array gets free.

*/