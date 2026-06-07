// Author : Yash Deshpande
// Date : 16-08-2025

#include <iostream>
using namespace std;

// Define Node class
// Define insertAtHead(), insertAtTail(), insertAtPosition()
// Define display(), deleteNode()

class Node{
public:
    int data;
    Node* next;
     
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);

    if(head == nullptr) {
        head = temp;
        tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);

    if(tail == nullptr) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void display(Node* head) {
    if(head == nullptr) {
        cout << "List is empty\n"; 
        return; 
    }
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtPosition(Node* &head, Node* &tail, int val, int pos) {
    // Checks for valid index 


    if(pos == 0) {
        insertAtHead(head, tail, val);
    }
    else {
        Node* ptr = head;
        for(int i = 0; i < pos-1; i++) {
            ptr = ptr->next;
        }
        if(ptr == tail) {
            insertAtTail(head, tail, val);
        }
        else {
            Node* temp = new Node(val);
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
}

void deleteNode(Node* &head, Node* &tail, int index) {
    // Checks for a valid index 

    if(head == nullptr) {
        cout << "Linked List is empty" << endl;
        return;
    }

    if(index == 0) {
        Node* temp = head; 
        if(head == tail) {
            tail = tail->next; 
        }
        head = head->next;
        delete temp;
        temp = nullptr;
    }
    else {
        Node* prev = nullptr;
        Node* curr = head;
        for(int i = 0; i < index; i++) {
            prev = curr; 
            curr = curr->next;
        }
        if(curr->next == nullptr) {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        curr = nullptr;
    }
}


int main()
{
    // ############### TEST for SLL ###############
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
    // Node *node1 = new Node(10);
    // Node *head = node1;
    // Node *tail = node1;
    // printForward(head);
    // cout<<getLength(head)<<endl;

    // insertAtHead(head, tail, 55);
    // insertAtHead(head, tail, 12);
    // insertAtHead(head, tail, 78);
    // printForward(head);


    // insertAtTail(head, tail, 25);
    // printForward(head);

    // insertAtPosition(head,tail,0,79);
    // printForward(head);

    // insertAtPosition(head,tail,4,85);
    // printForward(head);

    // insertAtPosition(head,tail,7,37);
    // printForward(head);
    // cout<<"tail : "<<tail->data<<endl;


    // deleteNode(head, tail, 7);
    // printForward(head);
    // cout<<"tail : "<<tail->data<<endl;
    // printBackward(tail);

    // deleteNode(head, tail, 2);
    // printForward(head);
    // cout<<"tail : "<<tail->data<<endl;
    // printBackward(tail);

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