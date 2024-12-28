// Author : Yash Deshpande
// Date : 29-03-2022

#include <iostream>
using namespace std;


//  Q. To declare a template function outside a using the scope resolution operator, ‘::’

template<class T>
class Harry
{
    public : 
    T data;

    Harry (T var)
    {
        data = var;
    }

    void display();
};

template <class T>     // -> This line is compulsory for fn declaration outside of class definition since the class is a template  
void Harry<T> :: display()
{
    cout<<data<<endl;
}

int main()
{
    Harry<int> h1(57);
    h1.display();

    Harry<float> h2(57.64);
    h2.display();

    Harry<char> h3('Y');
    h3.display();
    return 0;
}


/*

##############################################Extra Notes#####################################################

1. First write the function (for "display()") declaration in the class itself. 

2. Then move to the outside and use the scope resolution operator before the function and after the name of the class 
   Harry along with the data type T. We must specify the function data type, which is void here. 

3. And it must be preceded by the template declaration for class T.

4. When the class is a template its member functions also become templates & hence the template declaration at top 
   of the function definition.

5. When the class is a template whenever the class name is used the template parameter "<T>" is also used. 

*/