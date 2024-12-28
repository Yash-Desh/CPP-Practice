// Author : Yash Deshpande
// Date : 01-08-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public : 
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void insertNode(Node* &head, int value, int data)
{
    // create a node
    Node *temp = new Node(data);

    // If CDLL is empty
    if(head == NULL)
    {
        head = temp;
        temp->next = temp;
        temp->prev = temp;
    }

    else
    {
        // Data to be inserted after the node with the given "value"
        // Assuming "value" is present in the CDLL
        Node *ptr = head;
        while(ptr->data != value)
        {
            ptr = ptr->next;
        }

        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next->prev = temp;
        ptr->next = temp;
    }
}


void print(Node* &head)
{
    // when CDLL is empty
    if(head == NULL)
    {
        cout<<"CDLL is empty"<<endl;
        return;
    }

    Node *ptr = head;
    do
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    } while (ptr != head);
    cout<<endl;
}


void deleteNode(Node* &head, int value)
{
    // when CDLL is empty
    if(head == NULL)
    {
        cout<<"CDLL is empty"<<endl;
        return;
    }
    // Assuming "value" to be deleted is present
    else{
        Node *current = head->next;
        Node *previous = head;
        while(current->data != value)
        {
            previous = current;
            current = current->next;
        }

        // if CDLL has only 1 node
        if(current == previous)
        {
            head = NULL;
        }

        // if CDLL has more than 1 nodes 
        // & you wish to delete the head node
        else if(current == head)
        {
            head = previous;
        }

        previous->next = current->next;
        current->next->prev = previous;
        current->next = NULL;
        current->prev = NULL;
        delete current;
    }

}


int main()
{
    // creating a empty CDLL
    Node *head = NULL;
    insertNode(head, 3, 15);
    print(head);

    insertNode(head, 15, 56);
    print(head);

    insertNode(head, 56, 3);
    print(head);

    insertNode(head, 56, 66);
    print(head);

    deleteNode(head, 56);
    print(head);

    deleteNode(head, 66);
    print(head);

    deleteNode(head, 3);
    print(head);

    deleteNode(head, 15);
    print(head);

    return 0;
}