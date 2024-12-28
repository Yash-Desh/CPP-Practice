// Author : Yash Deshpande
// Date : 28-03-2022

#include <iostream>
using namespace std;

/*

template <class T1, class T2>
class class_name
{
    // Body
};

*/

template<class T1, class T2>
class myClass 
{
    public :
    T1 data1;
    T2 data2;

    myClass(T1 a, T2 b)
    {
        data1 = a;
        data2 = b;
    }

    void display ()
    {
        cout<<data1<<endl<<data2<<endl<<endl;
    }

};

int main()
{
    // 1st Use case
    myClass <int , char> obj1 (23, 's');
    obj1.display();

    // 2nd Use case
    myClass <int , float> obj2 (23, 43.54);
    obj2.display();

    // Any such combination of datatypes can be used to create an object 

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. To give you a short overview of how templates work with multiple parameters, you can think of it as a function where you have that power to pass different parameters of the same or different data types. 

2. The only effort it demands is the declaration of parameters. 

3. Any number of such comma seperated parameters can be used.


*/