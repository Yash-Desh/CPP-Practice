// Author : Yash Deshpande
// Date : 31-10-2022
// Tutor : Love Babbar(HW), TUF
// Code from TUF

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    // Constructor
    Stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        // If internal stack is full
        if (temp == NULL)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }

    void pop()
    {
        // if stack is empty
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack st;
    st.push(34);
    st.push(43);
    st.push(99);
    st.push(-2);
    cout << st.peek() << endl;
    if (st.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is Not empty" << endl;

    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    //
    st.pop();
    cout << st.peek() << endl;
    if (st.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is Not empty" << endl;
    return 0;
}