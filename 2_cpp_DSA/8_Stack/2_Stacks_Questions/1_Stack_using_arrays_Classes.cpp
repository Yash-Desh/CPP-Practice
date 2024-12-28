// Author : Yash Deshpande
// Date : 31-10-2022
// Tutor : Love Babbar

// ################################
// Fundamental Stack Operations are 
// 1. push()
// 2. pop()
// 3. peek()
// 4. isEmpty()
// 5. size()
// ################################

#include <iostream>
using namespace std;

class Stack
{
    // Data
private:
    int *arr;
    // here size is the length of the static array
    // created to implement the stack
    int size;
    // "top" Stores the index position of "top of stack"
    int top;     

    // Functions
public:
    // Constructor 
    Stack (int size)
    {
        this->size = size;
        top = -1;
        arr = new int [size];
    }

    // push
    void push (int data)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
        }
    }

    // pop()
    void pop()
    {
        if(top >= 0)
            top--;

        else
            cout<<"Stack Underflow"<<endl;
    }

    // peek()
    int peek()
    {
        if(top >= 0)
            return arr[top];    

        else
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;

        else 
            return false;
    }
};

int main()
{

    return 0;
}