// Author : Yash Deshpande
// Date : 16-08-2022
// Tutor : Abdul Bari


#include <iostream>
using namespace std;

class Node 
{
    public :
    int data;
    Node *next;
};

class Stack
{
    private:
    Node *top;

    public:
    // Default constructor
    Stack()                     
    {
        top = NULL;
    }

    void push (int x);
    int pop ();
    void display();
};


void Stack :: push(int x)
{
    Node *t = new Node;
    // check if the stack is full
    if (t == NULL)
        cout << "Stack is full" << endl;

    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}


int Stack :: pop ()
{
    int x = -1;
    // check if the stack is empty
    if(top == NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        Node *p = top;
        x = top->data;
        top = top->next;
        delete p;
    }
    return x;
}


void Stack :: display()
{
    Node *p = top;
    while(p != NULL)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    Stack stk;
    
    stk.push(45);
    stk.push(65);
    stk.push(4);
    stk.push(76);

    stk.display();

    cout<<stk.pop()<<endl;

    return 0;
}