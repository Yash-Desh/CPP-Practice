// Author : Yash Deshpande
// Date : 16-08-2025

#include <iostream>
using namespace std;

// Define Node class
// Define insertAtHead(), insertAtTail(), insertAtPosition()
// Define display(), deleteNode()


class Node 
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ~Node()
    {
        int value = this->data;
        if(this->next != nullptr)
        {
            delete next;
            this->next = nullptr;
        }
        cout<<value<<endl;
    }
};

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




void insertAtHead (Node* &head, Node* &tail, int data)
{
    Node *temp = new Node (data);
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail (Node* &head, Node* &tail, int data)
{
    Node* temp = new Node (data);
    if(tail == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition (Node* &head, Node* &tail, int position, int data)
{
    if(position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node* ptr = head;
    for(int i=0; i<position-1; i++)
    {
        ptr = ptr->next;
    }
    if(ptr->next == nullptr)
    {
        insertAtTail(head, tail, data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next->prev = temp;
    ptr->next = temp;

}

void deleteNode(Node* &head, Node* &tail, int position)
{
    if(position == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        head->prev = nullptr;
        delete temp;
    }

    Node *current = head;
    Node *previous = nullptr;
    for(int i=0; i<position; i++)
    {
        previous = current;
        current = current->next;
    }
    if(current->next == nullptr)
        tail = previous;
    else
        current->next->prev = previous;

    previous->next = current->next;
    current->next = nullptr;
    current->prev = nullptr;
    delete current;
}


int main()
{
    // // ############### TEST for SLL ###############
    // // Create a new Node
    // Node *node1 = new Node(150);

    // // Make it head node
    // Node *head = node1;
    // Node *tail = node1;
    // display(head);

    // // Insertion at beginning
    // insertAtHead(head, tail, 25);
    // display(head);

    // insertAtHead(head, tail, 67);
    // display(head);

    // // Insert at end
    // insertAtTail(head, tail, 63);
    // display(head);

    // insertAtTail(head, tail, 77);
    // display(head);

    // insertAtTail(head, tail, 71);
    // display(head);

    // insertAtTail(head, tail, 82);
    // display(head);

    // insertAtPosition(head, tail, 55, 5);
    // display(head);

    // deleteNode(head, tail, 4);
    // display(head);
    // cout << "tail : " << tail->data << endl;

    // /*
    // 150 
    // 25 150 
    // 67 25 150 
    // 67 25 150 63 
    // 67 25 150 63 77 
    // 67 25 150 63 77 71 
    // 67 25 150 63 77 71 82 
    // 67 25 150 63 77 55 71 82 
    // 7767 25 150 63 55 71 82 
    // tail : 82
    // */

    // ############### TEST for DLL ###############
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

    insertAtPosition(head,tail,0,79);
    printForward(head);

    insertAtPosition(head,tail,4,85);
    printForward(head);

    insertAtPosition(head,tail,7,37);
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

    /*
    10 
    1
    78 12 55 10 
    78 12 55 10 25 
    79 78 12 55 10 25 
    79 78 12 55 85 10 25 
    79 78 12 55 85 10 25 37 
    tail : 37
    Memory is freed for the node with data 37
    79 78 12 55 85 10 25 
    tail : 25
    25 10 85 55 12 78 79 
    Memory is freed for the node with data 12
    79 78 55 85 10 25 
    tail : 25
    25 10 85 55 78 79
    */

    return 0;
}