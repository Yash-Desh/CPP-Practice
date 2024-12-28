// Author : Yash Deshpande
// Date : 30-03-2022

#include<iostream>
#include<functional>   // -> necessary header file to be included to use functional objects
#include<algorithm>    // -> sort() algorithm is available through this header file
 
using namespace std;
 
int main(){
 
    // Function Objects (Functor) : A function wrapped in a class so that it is available like an object
    int arr[] = {1, 73, 4, 2, 54, 7};
    
    // sort in ascending order  i.e the default behaviour of the sort function is ascending order.
    sort(arr,arr+5);     // arr + 5 => means it sort only the first 5 elements
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<endl<<endl;

    // sort in ascending order
    sort( arr, arr+6, greater< int >( ));   // greater<int> () is the function object
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
 
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. What is a function object?
   A function object is a function wrapped in a class so that it is available as an object.
   That is, we can then use a function as an object. 

2. Why to substitute a function with an object ? 
   To make them all usable in an Object-Oriented Programming paradigm.

3. include the header file < functional>


*/