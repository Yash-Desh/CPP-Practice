// Author : Yash Deshpande 
// Date : 17-08-2022
// Tutor : Abdul Bari

// Q. Parenthesis matching with multiple types of parenthesis : stack   

#include <bits/stdc++.h>
using namespace std;


// structure to define a node of a LL
struct Node 
{
    char data;
    Node *next;
} *top = NULL;

// push 
void push(char x)     // tp = top pointer
{
    Node *t = new Node;
    if(t==NULL)
    {
        cout<<"Stack is full"<<endl;
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

// pop
char pop ()
{
    char x = '0';
    Node *temp = top;
    if(top == NULL)
    {
        cout<<"stack is empty";
    }
    else{
        x = top->data;
        top = top->next;
        delete temp;
    }
    return x;
}

// isEmpty()
bool isEmpty()
{
    if(top == NULL)
    {
        return true;
    }
    else{
        return false;
    }
}

void display()
{
    while(top)
    {
        cout<<top->data<<endl;
        top = top->next;
    }
}

char stackTop ()
{
    if(top == NULL)
        return '0';
    return top->data;
}

bool isBalanced (string exp)
{
    for(int i=0; i<exp.size(); i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}' )
        {
            if(isEmpty())
                return false;
            
            // ()
            char st = stackTop();
            if(exp[i] == ')' && st == '(')
                pop();

            if(exp[i] == ']' && st == '[')
                pop();

            if(exp[i] == '}' && st == '{')
                pop();
            
        }
    }
    return isEmpty();
}

int main()
{
    string Exp = "((){}";
    cout<<isBalanced(Exp)<<endl;
    return 0;
}