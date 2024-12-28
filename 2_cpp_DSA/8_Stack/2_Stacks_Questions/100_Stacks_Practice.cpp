// Author : Yash Deshpande
// Date : 09-02-2023

#include <bits/stdc++.h>
using namespace std;

class Stack {
    private: 
    int size;
    int top;
    int *arr;

    public:

    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int [this->size];
    }

    void push (int data)
    {
        if(size-top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop ()
    {
        if(top == -1)
            cout<<"Stack Underflow"<<endl;

        else
            top--;
    }


    int peek ()
    {
        if(top == -1)
            return -1;

        else
        {
            return arr[top];
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
    Stack st(5);
    st.push(59);
    cout<<st.isEmpty()<<endl;
    st.push(67);
    st.push(167);
    st.push(267);
    st.push(367);
    st.push(467);
    st.push(567);
    cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.isEmpty()<<endl;
    return 0;
}