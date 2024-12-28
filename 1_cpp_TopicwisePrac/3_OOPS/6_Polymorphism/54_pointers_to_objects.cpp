// Author : Yash Deshpande
// Date : 21-02-2022

#include<iostream>
using namespace std;

class Complex{
    int real, imaginary;
    
    public:
        void getData()
        {
            cout<<"The real part is "<< real<<endl;
            cout<<"The imaginary part is "<< imaginary<<endl;
        }

        void setData(int a, int b)
        {
            real = a;
            imaginary = b;
        }

};

int main()
{
    // Creating objects without pointers
    Complex C1;
    C1.setData(2,3);
    C1.getData();



    // *****Pointers to Objects*****

    // Creating objects using pointers
    Complex *ptr = &C1;
    (*ptr).setData(1, 5);       
    (*ptr).getData();            


    // Creating objects dynamically using pointers & new keyword
    Complex *ptr1 = new Complex;
    (*ptr1).setData(1, 54);       
    (*ptr1).getData();           

    

    // *****Arrow Opertor*****

    // Creating objects dynamically using pointers , new keyword & arrow operator 
    Complex *ptr2 = new Complex;
    ptr2->setData(1, 54);
    ptr2->getData(); 

    // Array of Objects
    Complex *ptr3 = new Complex[4]; 
    ptr3->setData(1, 4); 
    ptr3->getData();

    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. Pointers are used to store addresses of variables which have data types like int, float, double etc. 
   But pointer can also store the address of an object.

2. Pointers to Objects : We called the member function with pointers instead of object but still it will give 
                         same result because pointer is pointing to the address of that object.

3. Arrow Operator : We called the member function with pointers by using arrow operator “->” instead of the 
                    dot operator “.” but still it will give the same results.
*/
