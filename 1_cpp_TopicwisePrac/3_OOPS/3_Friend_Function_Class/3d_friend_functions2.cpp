// Author : Yash Deshpande
// Date : 31-01-2022

#include <iostream>
using namespace std;

class Y;  // Forward declare class Y

class X 
{
    int num;
    friend void add(X, Y);

    public:
    void setNum(int n)
    {
        num = n;
    }
};

class Y 
{
    int data;
    friend void add(X, Y);


    public:
    void setData(int n)
    {
        data = n;
    }
};

void add( X o1,Y o2)
{
    cout<<"Summing data of X and Y objects gives me "<< o1.num + o2.data;
}


int main()
{
    X a1;
    a1.setNum(5);

    Y a2;
    a2.setData(10);

    add(a1, a2);
     
    
    return 0;
}