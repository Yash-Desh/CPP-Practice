// Author : Yash Deshpande
// Date : 01-02-2023
// Date : 04-02-2023

#include <bits/stdc++.h>
using namespace std;

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

    ~Node ()
    {
        int value = data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"Node with data "<<value<<" deleted"<<endl;
    }
};

void insertAtHead(Node *&head, Node* &tail, int x)
{
    // Note : "&head" is used to make sure that all the changes
    //         are made inside the original LL
    //         "&head" is used to prevent pass by value
    
    // when the SLL is empty 
    if(head == NULL)
    {
        Node *temp = new Node (x);
        head = temp;
        tail =temp;
    }

    // when the SLL is NOT empty
    else 
    {
        // Create a new node
    Node *temp = new Node(x);

    // Attach the new node
    temp->next = head;
    head = temp;
    }
}

int sumOfElements (Node *head)
{
    int sum = 0;
    while(head != NULL)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int sumRecursive (Node *head)
{
    if(head == NULL)
        return 0;

    return sumRecursive(head->next)+head->data;
}

bool checkifSorted (Node *head) {
    // base case
    if(head->next == NULL)
        return true;

    if(head->data > head->next->data)
        return false;

    return checkifSorted(head->next);
} 

int main()
{
    Node *head = new Node (14);
    Node *tail = head;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, -20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, -40);
    cout<<"sum of elements "<<sumOfElements(head)<<endl;
    cout<<"sum of elements "<<sumRecursive(head)<<endl;
    cout<<checkifSorted(head)<<endl;
    return 0;
}