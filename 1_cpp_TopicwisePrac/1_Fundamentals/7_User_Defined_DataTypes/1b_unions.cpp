// Author : Yash Deshpande
// Date : 27-01-2022

#include <iostream>
using namespace std;

//Program to demonstrate use of unions
union money
{
    int rice;     //4 bytes
    char car;     //1 bytes
    float pounds; //4 bytes
};

int main()
{
    union money m1;
    m1.rice = 34;
    cout << m1.rice<<endl;
    cout<<"The size of the union m1 of type money = "<<sizeof(m1)<<endl;

    m1.car ='c';     // m1.rice has been removed from memory
    cout << m1.car<<endl;
    cout<<"The size of the union m1 of type money = "<<sizeof(m1)<<endl;

    cout << m1.rice; // This will give me garbage value since its no longer stored in the memory
    
    return 0;

}

/*

##############################################Extra Notes#####################################################

1. Unions are similar to structures but they provide better memory management then structures.  

2. Unions use shared memory so only 1 variable can be used at a time. 

3. We can only use 1 variable at a time otherwise the compiler will give us a garbage value
   The compiler chooses the data type which has maximum memory for the allocation.

4. Once we have assigned a value to the union field “rice”, now we cannot use other fields of the union 
   otherwise we will get garbage value.

*/