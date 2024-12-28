// Author : Yash Deshpande 
// Date : 22-08-2022
// Tutor : Abdul Bari

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


// Helper function to determine if the given character is operand
bool isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return false;
    else
        return true;
}



int Eval(char *postfix)
{
    int i=0;
    int x1,x2,r=0;

    for(int i=0; postfix[i] != '\0'; i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2=pop();
            x1= pop();
            switch(postfix[i])
            {
                case '+' : r = x1+x2;  break;
                case '-' : r = x1-x2;  break;
                case '*' : r = x1*x2;  break;
                case '/' : r = x1/x2;  break;
            }
            push(r);
        }
    }
    return top->data;
}




int main()
{
    char postfix []= "234*+82/-";
    cout<<Eval(postfix)<<endl;
    return 0;
}