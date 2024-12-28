// Author : Yash Deshpande
// Date : 01-04-2022

#include <iostream>
using namespace std;

template <class T>
class Arithmetic
{
    T a,b;

    public :
    Arithmetic (T a1, T b1);
    T add();
    T subtract();

};

template <class T>
Arithmetic<T> :: Arithmetic (T a1,T b1)
{
    a = a1;
    b = b1;
}

template <class T>
T Arithmetic<T> :: add()
{
    T c;
    c = a + b;
    return c;
}


template <class T>
T Arithmetic<T> :: subtract()
{
    T c;
    c = a - b;
    return c;
}

int main()
{
    Arithmetic<int> ar(10,5);
    cout<<ar.add()<<endl;


    Arithmetic<float> ar1(1.34,5.71);
    cout<<ar1.add();
    return 0;
}