// Author : Yash Deshpande
// Date : 28-03-2022

#include <iostream>
using namespace std;

template <class T1 = int, class T2 = float, class T3 = char>
class DataCls{
    public :
    T1 a;
    T2 b;
    T3 c;

    DataCls(T1 x,T2 y,T3 z)
    {
        a = x;
        b = y;
        c = z;
    }

    void display()
    {
        cout<<"The value of a is "<<a<<endl;
        cout<<"The value of b is "<<b<<endl;
        cout<<"The value of c is "<<c<<endl;
    }
};
int main()
{
    // 1st Use case
    DataCls<> h(4, 6.4, 'c');  // Notice the empty angular brackets that are used for default arguments
    h.display();
    cout << endl;
    
    // 2nd Use case
    DataCls<float, char, char> g(1.6, 'o', 'c');
    g.display();

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. To have default parameters is the ability to have default specifications about the data type, when it receives 
   no arguments from the main.

2. The constructor accepts the values featured by the main, and assigns them to our class variables a, b and c. 
   If the user specifies the data types along with the values, the compiler assigns them to T1 , T2 and T3, otherwise
   gives them the default ones, as specified while declaring the template itself.

*/