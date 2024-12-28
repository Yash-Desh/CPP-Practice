// Author : Yash Deshpande
// Date : 13-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


class Node 
{
    public : 
        int data;
        Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }


    // Destructor
    ~Node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory freed for the node with data "<<value<<endl;
    }
};


// Note : CLL doesn't neeed 2 pointers head & tail
// Any one is enough, since CLL doesn't have a 
// definite starting node
// we hv taken tail as the only pointer
// Also the insertion & deletion can be done using 
// data rather than index
// when using data , the new node is inserted right
// after the node having "element"

void insertNode (Node* &tail, int element, int x)
{
    // Assuming that the element is present in the list
    // When CSLL is empty
    if(tail == NULL)
    {
        Node *temp = new Node(x);
        tail = temp;
        temp->next = temp;
    }

    // when the CSLL is not empty 
    // Assuming "element" is present
    else
    {
        Node *current = tail;
        while(current->data != element)
        {
            current = current->next;
        }

        Node* temp = new Node(x);
        temp->next = current->next;
        current->next = temp;
    }
}


void print(Node *tail)
{
    // Empty CSLL
    if(tail == NULL)
    {
        cout<<"Empty CSLL"<<endl;
        return;
    }

    // Non-empty CSLL
    Node *temp = tail;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != tail);
    cout<<endl;
}



void deleteNode (Node *&tail, int val)
{
    // when the CSLL is empty
    if(tail == NULL)
    {
        cout<<"Empty CSLL"<<endl;
        return;
    }

    // when CSLL is not empty
    // Assuming the value is present in the LL
    else{
        // Important to follow initialization
        // This is for when there is only 1 node 
        // in the CSLL
        Node *prev = tail;
        Node *current = prev->next;
        
        while(current->data != val)
        {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;

        // CSLL has only one node
        if(current == prev)
        {
            tail = NULL;
        }

        // when CSLL >= 2 nodes 
        // deleted node is tail node
        else if(current == tail)
        {
            tail = prev;
        }
        current->next = NULL;
        delete current;
    }
}



int main()
{
    Node *tail = NULL;

    // insert in an empty CSLL
    // the value of element here
    // is of no use
    insertNode(tail, 15, 3);
    print(tail);


    // insertNode(tail, 3, 5);
    // print(tail);

    // insertNode(tail, 5, 8);
    // print(tail);

    // insertNode(tail, 5, 16);
    // print(tail);

    // insertNode(tail, 16, 90);
    // print(tail);
    
    // insertNode(tail, 5, 80);
    // print(tail);


    deleteNode(tail, 3);
    print(tail);


    return 0;
}