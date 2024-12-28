// Author : Yash Deshpande
// Date : 25-01-2022

/* Q. Program to create pattern : Rectangle Pattern

****
****
****
****
****


*/
#include <iostream>
using namespace std;

int main()
{
    int rows ,columns;
    cout<<"Enter number of rows : ";
    cin>>rows;
    cout<<"Enter number of columns : ";
    cin>>columns;

    for(int i = 0 ; i < rows; i++)    // ==> for (int i = 1 ; i <= rows; i++)
    {
        for(int j = 0; j < columns; j++)   // ==> for(int j = 1; j <= columns; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}