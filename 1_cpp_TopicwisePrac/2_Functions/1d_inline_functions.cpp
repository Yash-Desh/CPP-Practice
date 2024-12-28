// Author : Yash Deshpande
// Date : 25-01-2022

#include <iostream>
using namespace std;

// Function to demonstrate inline functions

inline int product(int a, int b)
{
    // Not recommended to use inline functions with static variables / recursive functions / loops etc
    // static int c=0; // This executes only once
    // c = c + 1; // Next time this function is run, the value of c will be retained
    return a * b;
}



int main()
{
    int a, b;
    cout << "Enter the value of a and b" << endl;
    cin >> a >> b;
    cout << "The product of a and b is " << product(a, b) << endl;
    cout << "The product of a and b is " << product(a, b) << endl;
    cout << "The product of a and b is " << product(a, b) << endl;
    cout << "The product of a and b is " << product(a, b) << endl;
   
    return 0;
}
