// Author : Yash Deshpande
// Date : 25-01-2022


/*

Q. Program to print the pattern : Half Pyramif after 180 rotation
    *
   **
  ***
 ****
*****

*/

#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout<<"Enter number of rows : ";
    cin>>rows;

    for(int i = 1; i <= rows; i++)
    {
        for(int j= 1; j<= rows; j++)
        {
            if(j<= (rows-i))
            {
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}