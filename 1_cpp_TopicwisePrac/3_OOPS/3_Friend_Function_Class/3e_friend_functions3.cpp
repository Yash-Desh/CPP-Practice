// Author : Yash Deshpande
// Date : 31-01-2022

#include <iostream>
using namespace std;

class c2;  // Forward declaration of class c2

class c1
{
private:
    int val1;

    friend void swap(c1 &, c2 &);

public:
    void setData(int n1)
    {
        val1 = n1;
    }

    void display(void)
    {
        cout<<"val1 = "<<val1<<endl;
    }
   
};

class c2
{
private:
    int val2;

    friend void swap(c1 &, c2 &);

public:
    void setData(int n2)
    {
        val2 = n2;
    }

    void display(void)
    {
        cout<<"val2 = "<<val2<<endl;
    }
   
};


void swap(c1 &o1, c2 &o2)
{
    int temp;
    temp = o1.val1;
    o1.val1 = o2.val2;
    o2.val2 = temp;

}


int main()
{
    c1 obj1;
    obj1.setData(5);
    obj1.display();

    c2 obj2;
    obj2.setData(4);
    obj2.display();

    swap(obj1, obj2);

    cout<<"The value of val1 after exchanging becomes: ";
    obj1.display();

    cout<<"The value of val2 after exchanging becomes: ";
    obj2.display();



    return 0;
}