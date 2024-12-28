// Author : Yash Deshpande
// Date : 13-09-2022

// C++ program to find total bit in given number
#include <iostream>
#include <cmath>
using namespace std;

unsigned countBits(unsigned int number)
{

    // log function in base 2
    // take only integer part
    return (int)log2(number) + 1;
}

// Driven program
int main()
{
    unsigned int num = 12;
    cout << countBits(num) << '\n';
    return 0;
}