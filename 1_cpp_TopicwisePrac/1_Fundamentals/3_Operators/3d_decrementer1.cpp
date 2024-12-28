// Author : Yash Deshpande
// Date : 19-01-2022

#include <iostream>
using namespace std;

int main()
{
    int i = 0;
        //0   //0    //1   //1
    i = i++ - --i  + ++i - i--;
    cout<<i<<endl;

    return 0;
}