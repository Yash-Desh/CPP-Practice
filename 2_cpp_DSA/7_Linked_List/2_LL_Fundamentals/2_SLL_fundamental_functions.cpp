// Author : Yash Deshpande
// Date : 04-02-2023
// Tutor : Abdul Bari



// *****************************************************************

// Here we solve fundamental questions related to LL in Iterative/Recursive 
// ways

// 1. display 
// 2. length of LL 
// 3. sum of LL elements 
// 4. Maximum / Minimum element
// 5. Linear Search

// ******************************************************************

#include <bits/stdc++.h>
using namespace std;

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
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

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

// Print a SLL : Iterative
void print(Node *&head)
{
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// Print a SLL : Recursive
void printRecursive (Node* head)
{
    // Base Case
    if(head == NULL)
    {
        cout<<endl;
        return;
    }
    Node* temp = head;
    cout<<temp->data<<" ";
    printRecursive(temp->next); 
}


// Length of LL : Iterative
int cnt (Node* &head)
{
    int cnt = 0;
    Node *p = head;
    while(p != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}


// Length of LL : Recursive
int cntRecursive (Node *head)
{
    // Base Case
    if(head == NULL)
        return 0;

    return cntRecursive(head->next) +1;
}


// Q. Sum of LL elements : Iterative
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


// Q. Sum of LL elements : Recursive
int sumRecursive (Node *head)
{
    if(head == NULL)
        return 0;

    return sumRecursive(head->next)+head->data;
}


// Q. Max element in a LL : Iterative
int maxInLL (Node *head)
{
    int maxi = INT_MIN;
    while(head != NULL)
    {
        maxi = max(maxi,head->data);
        head = head->next;
    }
    return maxi;
}


// Q. Max element in a LL : Recursive
int maxRecursive (Node *head)
{
    // Base Case
    if(head == NULL)
        return INT_MIN;

    int value = maxRecursive(head->next);
    return max(value,head->data);
}


// Q. Min element in a LL : Iterative
int minInLL (Node *head)
{
    int mini = INT_MAX;
    while(head != NULL)
    {
        mini = min(mini,head->data);
        head = head->next;
    }
    return mini;
}


// Q. Min element in a LL : Recursive
int minRecursive (Node *head)
{
    // Base Case
    if(head == NULL)
        return INT_MAX;

    int value = minRecursive(head->next);
    return min(value,head->data);
}


// Q. Linear Search : Iterative
Node * linearSearch (Node *head, int key)
{
    while(head != NULL)
    {
        if(head->data == key)
            return head;

        head = head->next;
    }
    return NULL;
}


// Q. Linear Search : Recursive
Node * linearSearchRecursive (Node *head, int key)
{
    // Base Case
    if(head == NULL)
        return NULL;

    if(head->data == key)
        return head;

    return linearSearchRecursive(head->next, key);
}


int main()
{
    Node *head = new Node (14);
    Node *tail = head;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, -40);

    // cout<<"max = "<<maxRecursive(head)<<endl;
    // cout<<"min = "<<minRecursive(head)<<endl;
    // cout<<"sum of elements "<<sumOfElements(head)<<endl;
    // cout<<"sum of elements "<<sumRecursive(head)<<endl;
    Node *temp = linearSearchRecursive(head, -40);
    if(temp)
    {
        cout<<"\nkey is found "<<temp->data<<endl;
    }
    else
    {
        cout<<"\nkey not found"<<endl;
    }
    return 0;
}