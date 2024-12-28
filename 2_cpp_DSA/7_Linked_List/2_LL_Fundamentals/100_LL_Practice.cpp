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
        int value = this->data;
        if (this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
        cout << "Value = " << value << endl;
    }
};

// Display function
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at head
void insertAtHead(Node *&head, Node *&tail, int value)
{
    Node *temp = new Node(value);

    // if LL is empty
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    // if LL is not empty
    else
    {
        temp->next = head;
        head = temp;
    }
}

// Insert at tail
void insertAtTail(Node *&head, Node *&tail, int value)
{
    Node *temp = new Node(value);
    // if LL is empty
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }

    // is LL is NOT empty
    {
        tail->next = temp;
        tail = temp;
    }
}

// Insert at position
void insertAtPosition(Node *&head, Node *&tail, int value, int index)
{
    if (index == 0)
    {
        insertAtHead(head, tail, value);
    }

    Node *ptr = head;
    int cnt = 0;
    while (cnt < index - 1)
    {
        ptr = ptr->next;
        cnt++;
    }

    if (ptr->next == NULL)
    {
        insertAtTail(head, tail, value);
        return;
    }

    Node *temp = new Node(value);
    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteNode(Node *&head, Node *&tail, int index)
{
    if (index == 0)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *current = head;
        Node *previous = NULL;
        int cnt = 0;
        while (cnt < index)
        {
            previous = current;
            current = current->next;
            cnt++;
        }

        if(current->next == NULL)
        {
            tail = previous;
        }

        previous->next = current->next;
        current->next = NULL;
        delete current;
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