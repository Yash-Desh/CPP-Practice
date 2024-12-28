// Author : Yash Deshpande 
// Date : 22-02-2022

#include <iostream>
using namespace std;
class A
{
    int a;
    
    public:
         A & setData(int a){
            this->a = a;
            return *this; // returning reference of an object
        }

        void getData(){
            cout<<"The value of a is "<<a<<endl;
        }
};

int main(){
    A a;
    a.setData(4).getData();  // No need for a seperate a.getData()
    // a.getData();
    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. “this” pointer can be used to return a reference to the invoking object.

2. In the function “setData” the reference of the object is returned using “this” pointer.

3. In the main program by using a single object we have made a chain of the function calls. 

4. The function “setData” is returning an object on which we have used the “getData” function. 
   So we don’t need to call the function “getData” explicitly

*/
