// Author : Yash Deshpande
// Date : 01-08-2023

#include <iostream>
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

    ~Node()
    {
        int temp = this->data;
        if(this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        } 
        cout<<"Element deleted is "<<temp<<endl;
    }
};

void insertAtHead (Node* &head, Node* &tail, int data)
{
    Node *temp = new Node (data);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void insertAtTail (Node* &head, Node* &tail, int data)
{
    Node *temp = new Node(data);

    if(tail == NULL)
    {
        tail = temp;
        head = temp;
    }

    else{
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position)
{
    // check for a valid position

    if(position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;
    for(int i=0; i<position-1; i++)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        insertAtTail(head, tail, data);
    }

    Node *to_insert = new Node (data);
    to_insert->next = temp->next;
    temp->next = to_insert;

}

void display(Node *&head)
{
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return;
    }
    
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode (Node* &head, Node* &tail, int position)
{
    // check the position against the length

    if(head == NULL)
    {
        return;
    }

    if(position == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        for(int i=0; i<position; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if(curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

}

int main()
{
    // Create a new Node
    Node *node1 = new Node(150);

    // Make it head node
    Node *head = node1;
    Node *tail = node1;
    display(head);

    // Insertion at beginning
    insertAtHead(head, tail, 25);
    display(head);

    insertAtHead(head, tail, 67);
    display(head);

    // Insert at end
    insertAtTail(head, tail, 63);
    display(head);

    insertAtTail(head, tail, 77);
    display(head);

    insertAtTail(head, tail, 71);
    display(head);

    insertAtTail(head, tail, 82);
    display(head);

    insertAtPosition(head, tail, 55, 5);
    display(head);

    deleteNode(head, tail, 4);
    display(head);
    cout << "tail : " << tail->data << endl;

    return 0;
}