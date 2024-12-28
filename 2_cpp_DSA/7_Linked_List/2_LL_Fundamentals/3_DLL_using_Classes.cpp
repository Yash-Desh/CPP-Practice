// Author : Yash Deshpande
// Date : 12-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public : 
        int data;
        Node *prev;
        Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor
    ~Node ()
    {
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory is freed for the node with data "<<value<<endl;
    }
}; 


// Print DLL
void printForward(Node* head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void printBackward (Node *tail)
{
    Node *temp = tail;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}


// Length of a DLL
int getLength (Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}


// Insertion at the beginning
void insertAtHead (Node* &head, Node* &tail, int x)
{
    if(head == NULL)
    {
        // when the DLL is empty 
        Node *temp = new Node (x);
        head = temp;
        tail = temp;
    }
    else 
    {
        // when the DLL is not empty
        Node *temp = new Node(x);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}



// Insertion at the end
void insertAtTail (Node* &head ,Node* &tail, int x)
{
    // When the DLL is empty 
    if(tail == NULL)
    {
        Node *temp = new Node (x);
        head = temp;
        tail = temp;
    }
    // when the DLL is not empty
    else
    {
        Node *temp = new Node (x);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}


// Insert at any position
// Note : This function does
// not check for invalid index
// This function assumes the DLL
// to be zero indexed
void insertAtPostion(Node* &head, Node* &tail, int index, int x)
{

    // Inserting at beginning
    if(index == 0)
    {
        insertAtHead(head, tail, x);
        return;
    }

    // Create a pointer to traverse the SLL
    // Depending on how you traverse , 
    // the SLL can be zero-indexed or 1-indexed
    Node *ptr = head;
    for(int i=0; i<index-1; i++)
    {
        ptr = ptr->next;
    }

    // Insert at end
    // This makes sure the tail pointer is 
    // also updated
    if(ptr->next == NULL)
    {
        insertAtTail(head, tail, x);
        return;
    }

    // Insert in middle
    // Create a new Node
    Node *temp = new Node(x);

    temp->next = ptr->next;
    ptr->next->prev = temp;
    ptr->next = temp;
    temp->prev = ptr;
}



// Deletion at any position
void deleteNode (Node* &head, Node* &tail, int index)
{
    // Deletion of head node
    if(index == 0)
    {
        Node *p = head;
        p->next->prev = NULL;
        head = p->next;
        p->next = NULL;
        delete p;
    }
    // deletion of middle/last node
    else
    {
        Node *current = head;
        Node *previous = NULL;
        for(int i=0; i<index; i++)
        {
            previous = current;
            current = current->next;
        }

        if(current->next == NULL)
        {
            tail = previous;
        }
        else
        {
            current->next->prev = previous;
        }
        previous->next = current->next;
        current->prev = NULL; 
        current->next = NULL;
        delete current;
    }
}


int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    printForward(head);
    cout<<getLength(head)<<endl;

    insertAtHead(head, tail, 55);
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 78);
    printForward(head);


    insertAtTail(head, tail, 25);
    printForward(head);

    insertAtPostion(head,tail,0,79);
    printForward(head);

    insertAtPostion(head,tail,4,85);
    printForward(head);

    insertAtPostion(head,tail,7,37);
    printForward(head);
    cout<<"tail : "<<tail->data<<endl;


    deleteNode(head, tail, 7);
    printForward(head);
    cout<<"tail : "<<tail->data<<endl;
    printBackward(tail);

    deleteNode(head, tail, 2);
    printForward(head);
    cout<<"tail : "<<tail->data<<endl;
    printBackward(tail);

    return 0;
}