// Author : Yash Deshpande 
// Date : 15-08-2022
// Tutor : Striver

// Q. To return the nth element in the fibonacci series
// 0 - 0th element
// 1 - 1st element
// 1 - 2nd element
// 2 - 3rd element
// 3 - 4th element
// 5 - 5th element
// 8 - 6th element
// .      .
// .      .
// .      .
// ... an so on


// NOTE :  time :   O(2^n)  i.e exponential
//         This function is an example of multiple recursion calls or tree recursion


#include <iostream>
using namespace std;

int fib(int n)
{
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
} 

int main()
{
    cout<<fib(7)<<endl;
    return 0;
}