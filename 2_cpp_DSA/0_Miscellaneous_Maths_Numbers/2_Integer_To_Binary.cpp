// Author : Yash Deshpande
// Date : 14-08-2022
// Tutor : Love Babbar 

/* Q. To convert an integer to a binary number
      i) positive integer
      ii) negative integer
*/
#include <bits/stdc++.h>
using namespace std;






// toBinary() is a function to convert positive integers to binary numbers
int toBinary (int num)
{
    int binAns = 0;     // final ans
    int i=0;            // count for exponent
    while(num != 0)
    {
        int bit = num & 1;                          // extract the last bit of the number
        binAns = (bit* pow(10,i)) + binAns;         // formula 
        num = num >>1;                              // right shift the number by 1 digit
        i++;                                        // increment the exponent
    }
    return binAns;
}





// toSignedBinary() is a function to convert +ve / -ve integers to binary
int toSignedBinary (int n)
{
    int num = n < 0 ? (-1*n) : n;           // Take the positive of the input integer 
    
    // common part
    int binAns = 0;     // final ans
    int i=0;            // count for exponent
    while( num != 0)
    {
        int bit = num & 1;                          // extract the last bit of the number
        binAns = (bit* pow(10,i)) + binAns;         // formula 
        num = num >>1;                              // right shift the number by 1 digit
        i++;                                        // increment the exponent
    }

    // Extra processing if the given input is negative
    // Taking 2s complement
    if(n < 0)                                     
    {
        // Taking 1s complement of the number
        binAns = ~binAns; 

        // Taking 2s complement of the number                          
        binAns += 1;
    }
    return binAns;
}

int main()
{
    int x = 125;
    cout<<toBinary(x)<<endl;

    cout<<toSignedBinary(-125)<<endl;
    
    return 0;
}
