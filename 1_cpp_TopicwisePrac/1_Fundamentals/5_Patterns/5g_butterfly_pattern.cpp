// Author : Yash Deshpande
// Date : 25-01-2022

/*

Q. Program to print the pattern : Butterfly Pattern

*      *
**    **
***  ***
********
********
***  ***
**    **
*      *


*/

#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout<<"Enter number of rows : ";
    cin>>rows;

    // Loops for upper half 
    for(int i= 1; i<= rows; i++ )
    {
        for(int j = 1; j<= i; j++)   // Loop - 1 : for the 1st set of stars
        {
            cout<<"*";
        }
        int space = 2*rows - 2*i;
        for (int j = 1; j<= space; j++ )  // Loop - 2 : for the spaces
        {
            cout<<" ";
        }
        for(int j = 1; j<= i; j++)   // Loop - 3 : for the 2nd set of stars
        {
            cout<<"*";
        }
        cout<<endl;

    }

    // Loops for lower half 
    for(int i= rows; i>= 1; i-- )
    {
        for(int j = 1; j<= i; j++)
        {
            cout<<"*";
        }
        int space = 2*rows - 2*i;
        for (int j = 1; j<= space; j++ )
        {
            cout<<" ";
        }
        for(int j = 1; j<= i; j++)
        {
            cout<<"*";
        }
        cout<<endl;

    }

    return 0;
}