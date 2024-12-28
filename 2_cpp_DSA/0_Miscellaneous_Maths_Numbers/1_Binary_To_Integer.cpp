// Author : Yash Deshpande
// Date : 14-08-2022

// Q. To convert binary numbers to integers

#include <bits/stdc++.h>
using namespace std;

// toInteger() is a function to convert binary numbers into integers
int toInteger (int bin)
{
    int intAns = 0;
    int i = 0;              // exponent counter
    while(bin != 0)
    {
        int digit = bin % 10;
        if(digit == 1)
        {
            intAns = intAns + pow(2, i);
        }
        i++;                // increment the exponent
        bin = bin / 10;
    }
    return intAns;
}

int main()
{
    int binNum = 1100;
    cout<<toInteger(binNum)<<endl;
    return 0;
}