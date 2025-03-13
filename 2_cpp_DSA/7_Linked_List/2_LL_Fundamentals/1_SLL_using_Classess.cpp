// Author : Yash Deshpande
// Date : 11-10-2022
// Tutor : Love Babbar  

#include <bits/stdc++.h>
using namespace std;

// Implementing a node using Classes
class Node
{
public:
    int data;
    Node *next;

    // Using Parameterized constructor
    // Called whenever you create a new Node

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    // Called whenever you delete a Node
    // Or free memory
    ~Node()
    {
        // store the data of the current node
        int value = this->data;

        // if the current node is NOT the last node
        if (this->next != NULL)
        {
            // Delete the next node
            // This line will recursively run to delete all the nodes
            // present in the LL after the current node
            delete next;

            // After deleting the subsequent nodes, the next pointer 
            // of the current node is set to NULL to prevent any 
            // dangling pointers.
            this->next = NULL;
        }
        // print the data of the current node
        cout << "Memory is free for node with data " << value << endl;
    }
};

// Insert at beginning
void insertAtHead(Node *&head, Node* &tail, int x)
{
    // Note :   &head is the head pointer passed by reference
    //          "&head" is used to make sure that all the changes
    //         are made inside the original LL
    //         "&head" is used to prevent pass by value
    
    // when the SLL is empty 
    if(head == NULL)
    {
        Node *temp = new Node(x);
        head = temp;
        tail = temp;
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

// Insert at End
void insertAtTail(Node *&head, Node *&tail, int x)
{
    // when the SLL is empty
    if (tail == NULL)
    {
        Node *temp = new Node(x);
        tail = temp;
        head = temp;
    }

    // when the SLL is NOT empty
    else
    {
        // create a new Node
        Node *temp = new Node(x);

        // Attach the new node at the tail
        tail->next = temp;
        tail = temp;  
    }
}

// Insert at any position
// Note : This function does not check for invalid index
// This function assumes the SLL to be zero-indexed
void insertAtPostion(Node *&head, Node *&tail, int index, int x)
{
    // check if the index is a valid index

    // Inserting at beginning
    if (index == 0)
    {
        insertAtHead(head, tail, x);
        return;
    }

    // Traverse the SLL
    // Depending on how you traverse, the SLL can be zero-indexed or 1-indexed
    Node *ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }

    // Insert at end
    // This makes sure the tail pointer is also updated
    if (ptr->next == NULL)
    {
        insertAtTail(head, tail, x);
        return;
    }

    // Insert in middle
    Node *temp = new Node(x);
    temp->next = ptr->next;
    ptr->next = temp;
}

// Deletion at any position
void deleteNode(Node *&head, Node *&tail, int index)
{
    // Deletion of head node
    if (index == 0)
    {
        Node *p = head;
        head = head->next;
        p->next = NULL;
        delete p;
    }
    // deletion of middle/last node
    else
    {
        Node *current = head;
        Node *prev = NULL;
        for (int i = 0; i < index; i++)
        {
            prev = current;
            current = current->next;
        }

        // Deleting Tail Node
        if (current->next == NULL)
        {
            tail = prev;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

// Print a SLL : Iterative
void print(Node *&head)
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


int main()
{

    //***************************
    // Insert at beginning of SLL
    //***************************

    // Create a new Node
    Node *node1 = new Node(150);

    // Make it head node
    Node *head = node1;
    print(head);

    Node *tail = head;

    // Insertion at beginning
    insertAtHead(head, tail, 25);
    print(head);

    insertAtHead(head, tail, 67);
    print(head);

    // //**********************
    // //  Insert at End of SLL
    // //**********************

    // // Note : "tail pointer" is not a
    // // necessity , insertion at end can
    // // also be done using SLL traversal

    // // Create a new Node
    // Node * node1 = new Node(44);

    // // Make it head
    // Node *head = node1;

    // // Make it Tail
    // Node *tail = node1;
    // print(head);

    // // Insert at end
    // insertAtTail(tail, 63);
    // // print(head);

    // insertAtTail(tail, 77);
    // print(head);

    // // **********************
    // // Insert at any position
    // // **********************

    // // Create a new Node
    // Node * node1 = new Node(44);

    // // Make it head
    // Node *head = node1;

    // // Make it Tail
    // Node *tail = node1;
    // print(head);

    // insertAtTail(tail, 63);
    // insertAtTail(tail, 105);
    // insertAtHead(head, 67);
    // insertAtHead(head, -9);
    // print(head);

    // insertAtPostion(head, tail, 5, 55);
    // print(head);

    // // ************************
    // // Deletion at any position
    // // ************************

    // // NOTE : Deletion can be done using index & value

    // // Create a new Node
    // Node *node1 = new Node(44);

    // // Make it head
    // Node *head = node1;

    // // Make it Tail
    // Node *tail = node1;
    // print(head);

    // insertAtTail(head, tail, 63);
    // insertAtTail(head, tail, 105);
    // insertAtHead(head, tail, 67);
    // insertAtHead(head, tail, -9);
    // print(head);
    // cout << "tail : " << tail->data << endl;

    // deleteNode(head, tail, 4);
    // print(head);
    // cout << "tail : " << tail->data << endl;

    return 0;
}