// Author : Yash Deshpande
// Date : 25-07-2023
// Tutor : Love Babbar Weekly Contest - 3

#include <bits/stdc++.h>
using namespace std;


// My Approach : AC
// TC : O(log n) ...where n is the largest of the 3 integers a,b,c
// SC : O(1)

int makeItEqual(int a, int b, int c)
{
    // Write your code here.

    // Store the result of the operation a & b
    int result = a & b;

    // store the number moves to be performed
    int moves = 0;

    // check for each bit of c
    while (c > 0)
    {
        // Determine corresponding bits of result and c
        int cbit = c & 1;
        int resultBit = result & 1;

        // if corresponding bits are unequal
        if (cbit != resultBit)
        {
            // if c has a set bit
            if (cbit == 1)
            {
                // Both a and b must hv corresponding set bit 
                if ((a & 1) == 0)
                    moves++;

                if ((b & 1) == 0)
                    moves++;
            }

            // if c has a reset bit
            else
            {
                // either of a or b can hv the corresponding bit = 0
                moves++;
            }
        }
        c = c >> 1;
        a = a >> 1;
        b = b >> 1;
        result = result >> 1;
    }

    // result is non-zero even after c reduced to zero
    while (result > 0)
    {
        // either of a or b can hv the corresponding bit = 0
        int resultBit = result & 1;
        if (resultBit == 1)
            moves++;
        result = result >> 1;
    }

    return moves;
}

int main()
{

    return 0;
}