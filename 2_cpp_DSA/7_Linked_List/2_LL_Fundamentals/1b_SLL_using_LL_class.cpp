// Author: Yash Deshpande
// Date  : 16-05-2026
// Tutor : Medium
// Link  : https://medium.com/@RobuRishabh/beginners-guide-to-linked-list-in-c-d8445ef906ab


#include <bits/stdc++.h>
using namespace std;

// Define a Node class
class Node{
  public:
    int data; 
    Node* next; 

    // Constructor for convenience
    Node(int value) : data(value), next(nullptr) {}
};

// Class for singly linked list
class LinkedList{
private:
  Node* head; // Pointer to the head of the list

public: 
    // Constructor to initialize an empty list
    LinkedList() {
        head = nullptr;
    }

    // Destructor to free all allocated memory
    // Why is this destructor compulsory ? 
    // memory allocated by insertAtTail won't 
    // be freed when the LinkedList object goes out of scope.
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to insert a node at the end
    void insertAtTail(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode; // If list is empty, make newNode the head
        }
        else{
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next; // Traverse to the last node
            }
            temp->next = newNode; // Link the last node to newNode
        }
    }


    // Function to delete a Node by Value
    void deleteByValue(int value){
        if(head == nullptr){
            cout << "Linked List is empty" << endl;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        while(curr != nullptr) {
            if(curr->data == value) {
                break;
            }
            prev = curr;
            curr = curr->next; 
        }

        // Value NOT Found
        if(curr == nullptr) {
            cout << "Value not found" << endl; 
            return;
        }

        if(curr == head) {
            head = head->next;
        }
        else {
            prev->next = curr->next;
        }
        curr->next = nullptr;
        delete curr;
        curr = nullptr;
    
    }
    
    void display() {
        if(head == nullptr) {
            cout << "Linked List is empty\n";
            return;
        }
        Node* ptr = head;
        while(ptr) {
            cout << ptr->data << " ";
            ptr = ptr->next; 
        }
        cout << endl;
    }

};

int main() {
    LinkedList list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    cout << "Linked List: ";
    list.display();

    list.deleteByValue(20);

    cout << "After Deleting 20: ";
    list.display();

    return 0;
}