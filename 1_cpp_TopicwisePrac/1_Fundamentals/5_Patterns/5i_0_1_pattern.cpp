// Author : Yash Deshpande
// Date : 26-01-2022

/*

Q. Program to print the pattern : 0-1 Pattern

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1


*/

#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout<<"Enter number of rows : ";
    cin>>rows;

    for(int i = 1; i<= rows; i++)
    {
        for(int j =1 ;j<=i;j++)
        {
            if((i+j)%2 ==0)  // Notice that for i+j of a particular position if even then the  element is always = 1
            {
                cout<<"1 ";
            }
            else
            {
                cout<<"0 ";
            }

        }
        cout<<endl;
    }


    return 0;
}