// Author : Yash Deshpande 
// Date : 25-03-2022

#include <iostream>
using namespace std;

struct Test
{
    int A[5];
    int n;  // n represents the size of the array
};

void func(struct Test t)
{
    t.A[0] = 35;
    t.A[1] = 27;   // These changes are local the func() function
    cout<<"Inside the function"<<endl;
    for(int i=0; i<(t.n); i++)
    {
        cout<<t.A[i]<<" ";
    } 
    cout<<endl;
}
int main()
{
    struct Test t1 = {{12,3,45,8,0},5};
    func(t1);
    cout<<"\nOutside the function"<<endl;
    for(int i=0; i<(t1.n); i++)
    {
        cout<<t1.A[i]<<" ";
    } 
    cout<<endl;
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Arrays can only be "Passed by Address" but structs can be passed by any "Value" /"Address"/ "Reference"

2. Thus structs containing arrays can be "Passed by Value"

3. Any modifications made to the arrays which are struct members inside functions are not seen outside the function


*/