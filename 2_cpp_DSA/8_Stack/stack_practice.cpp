#include <iostream>
using namespace std;

// array-based stack
class Stack
{
    private:
    int top;
    int *arr;
    int size;

    public:
    Stack(int size)
    {
        this->size = size;
        arr = new int [this->size];
        int top = -1;
    }

    void push(int data)
    {
        if(size <= top+1)
        {
            cout<<"stack overflow"<<endl;
            return;
        }
        else
        {
            top++;
            arr[top] = data; 
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"stack is empty"<<endl;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if(top == -1)
        {
            cout<<"stack is empty"<<endl;
        }
        else
        {
            return arr[top];
        }
    }
};

// linked-list based stack
class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int main()
{
    
    return 0;
}