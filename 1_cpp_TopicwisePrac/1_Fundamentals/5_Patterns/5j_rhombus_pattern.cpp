// Author : Yash Deshpande
// Date : 27-01-2022

/*

Q. Program to print the pattern : Rhombus Pattern

    *****
   *****
  *****
 *****
*****

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i =1; i<= n; i++)
    {
        for(int j = 1; j<=n-i;j++)
        {
            cout<<" ";
        }
        for(int j =1;j<=n; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}