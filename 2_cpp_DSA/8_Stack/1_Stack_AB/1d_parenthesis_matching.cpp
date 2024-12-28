// Author : Yash Deshpande 
// Date : 16-08-2022
// Tutor : Abdul Bari

#include <bits/stdc++.h>
using namespace std;

// struct of stack
struct Stack 
{
    int size;
    int top;
    char *S;
};

// stack push
void push (Stack *st, char x)
{
    // If the stack is full 
    if(st->top == st->size-1)
        cout<<"stack overflow"<<endl;
    
    // if the stack is not full 
    else{
        st->top++;
        st->S[st->top] = x;
    }
} 


// stack pop
char pop (Stack *st)             // stack is modified hence passed by address
{
    char x =-1;                  // variable to store popped element
    // if the stack is empty 
    if(st->top == -1)
    {
        cout<<"stack underflow"<<endl;
    }

    // if the stack is not empty
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

// function to check if stack is empty
bool isEmpty(Stack st)
{
    return st.top == -1 ? 1 : 0;
}


// function to check for parenthesis matching
bool isBalanced (char * exp)
{
    // initialize the stack
    Stack st;
    st.top = -1;
    st.size = strlen(exp);
    st.S = new char [st.size];
    for(int i=0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(&st, exp[i]);
        }
        else if(exp[i]==')')
        {
            if(isEmpty(st))
                return false;
            pop(&st);
        }
    }
    return isEmpty(st) ? true : false;
}

int main()
{
    char Exp[] = "((a+b)*(c-d)))))";
    cout<<isBalanced(Exp)<<endl;
    return 0;
}