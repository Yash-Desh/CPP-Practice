// Author : Yash Deshpande 
// Date : 15-08-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

// struct of stack
struct stack 
{
    int size;
    int top;
    int *S;
};


// function to create a stack
void create (stack *st)
{
    cout<<"Enter size of stack : ";       // Take size of stack as user input
    cin>>st->size;
    st->top = -1;                         // set the top of stack to -1
    st->S = new int [st->size];           // dynamic array of user input size
}

// function to display stack elments
void display(stack st)
{
    int i;
    for(i = st.top; i>=0; i--)
    {
        cout<<st.S[i]<<" ";
    }
    cout<<endl;
}

// stack push
void push (stack *st, int x)
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
int pop (stack *st)             // stack is modified hence passed by address
{
    int x =-1;                  // variable to store popped element
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


// function to return the value at the given index
int peek(stack st, int index)
{
    int x = -1;
    if(st.top - index +1 < 0)
        cout<<"Invalid Index"<<endl;
    else
    {
        x = st.S[st.top - index + 1];
    }
    return x;
}


// function to check if stack is empty
bool isEmpty(stack st)
{
    return st.top == -1 ? 1 : 0;
}


// function to check if stack is full
bool isFull (stack st)
{
    if(st.top == st.size-1)
        return 1;
    else
        return 0;
}


// function to return the top of stack
int stackTop (stack st)
{
    if(st.top == -1)
        return -1;
    else 
        return st.S[st.top];
}

int main()
{
    stack st;
    create(&st);

    push(&st , 10);
    push(&st , 20);
    push(&st , 30);
    push(&st , 40);
    push(&st , 10);
    push(&st , 60);
    push(&st , 70);

    cout<<pop(&st)<<endl;
    // cout<<pop(&st)<<endl;
    // cout<<pop(&st)<<endl;

    display(st);
    cout<<isEmpty(st)<<endl;
    cout<<isFull(st)<<endl;

    return 0;
}