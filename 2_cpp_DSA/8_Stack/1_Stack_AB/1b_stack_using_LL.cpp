// Author : Yash Deshpande
// Date : 16-08-2022
// Tutor : Abdul Bari
  
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *top = NULL; // Node type global pointer to point at stack top
               // creating such global pointers is advisable only when
               // the program contains 1 single stack
               // Else create top pointer in the main()

void push(int x)
{
    Node *t = new Node;
    // check if the stack (i.e heap) is full
    if (t == NULL)
        cout << "Stack is full" << endl;

    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}


int pop ()
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


void display()
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
    // If top pointer is a global pointer then
    // the stack functions need not take the stacktop
    // as parameter

    // If the top pointer is declared inside the main()
    // then all the functions will take the stack top as
    // a parameter

    push(25);
    push(17);
    push(8);
    push(22);
    push(229);
    display();

    pop();
    pop();
    display();



    return 0;
}