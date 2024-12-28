// Author : Yash Deshpande
// Date : 25-01-2022

/*

Q. Program to print the pattern : Floyd's Triangle
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15


*/

#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout<<"Enter number of rows : ";
    cin>>rows;

    int num = 1;
    for(int i = 1; i<=rows; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            cout<<num++;
        }
        cout<<endl;
    }

    return 0;
}