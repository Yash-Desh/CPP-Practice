// Author : Yash Deshpande
// Date : 20-08-2022
// Tutor : Abdul Bari

// Infix to Postfix conversion using Method -1
// Operands have no precedence
// Only 4 operators are used +,-,*,/
// No other operators are used 
// Associativity of all the 4 operators used here is L->R

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
} *top = NULL; // Node type global pointer to point at stack top
               // creating such global pointers is advisable only when
               // the program contains 1 single stack
               // Else create top pointer in the main()

void push(char x)
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

int pop()
{
    char x = -1;
    // check if the stack is empty
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
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
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

// Helper function to find the precedence of an operator
// This function defines the sorting sorting behaviour
// User can set precedence as he desires for as many 
// operators he likes , albeit always following the 
// fundamental conditions of operator precedence
int pre(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0; // return 0 for any other character
} // needed when the stack is empty

// Helper function to determine if the given character is operand
bool isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return false;
    else
        return true;
}

// function to convert infix to postfix
char *InToPost(char *infix)
{
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len + 2]; // +2 is added to accomodate '\0' in the end
                                 // & the extra character pushed before calling the
                                 // function '#'
    int i = 0, j = 0;
    
    while (infix[i] != '\0')
    {
        // For operands
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }

        // for operators
        else
        {
            if (pre(infix[i]) > pre(top->data)) //  star step
            {
                push(infix[i]);
                i++;
            }

            else
            {
                postfix[j++] = pop(); // On popping the stack, the index on infix doesnt change
            }                         // This is why we need while loop
        }
    }

    // for items remaining items
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Critical step
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e"; // NOTE : a pointer is initialized with string value
                           // A normal c-string array would have worked as well

    push('#');  // NOTE : This code is an exact copy of the one 
                // taught by Abdul Bari
                // '#' is pushed before calling the function so that stack never 
                // becomes asolutely empty

    char *postfix = InToPost(infix);
    cout << postfix << endl;

    return 0;
}