// Author : Yash Deshpande
// Date : 29-03-2022

#include <iostream>
using namespace std;

template<class T1>
void swapp(T1 &a , T1 &b)
{
    T1 temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int var1 = 34, var2 = 55;
    swapp(var1, var2);
    cout<<"After swapp() "<<var1<<" & "<<var2<<endl<<endl;


    float var3 = 34.76, var4 = 5.15;
    swapp(var3, var4);
    cout<<"After swapp() "<<var3<<" & "<<var4<<endl<<endl;
    return 0;
}