// Author : Yash Deshpande 
// Date : 27-07-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

// structure to define a Node
struct Node
{
    int data;                   // node data 
    struct Node *next;          // pointer to next node
}*first = NULL;                 // "first" is a global pointer of the "Node type" , initialized to point at nothing


// function to create a LL from an array
// n = number of elements in the array
void create(int Arr[], int n)
{
    
    struct Node *t;             // Temporary pointer of node type to help create new nodes
    struct Node *last;          // ptr to the last node in the LL , to help attach new nodes after the last node

    // Creating the 1st(head) node
    first = new Node;
    first->data = Arr[0];
    first->next = NULL;
    last = first;               // LL contains only 1 node , thus first node is the last node

    // Creating the remaining nodes
    for(int i=1; i<n; i++)      // i = 1 bcuz the 1st node is already created using Arr[0]
    {
        // t creates a new node
        t = new Node;  
        t->data = Arr[i];
        t->next = NULL;

        // Attaching the new node to the back of the last node of the LL
        last->next = t;
        last = t;               //new node is now the last node 
    }
}


// display() function
void display(struct Node *p)   // p is a "Node type" pointer that traverses the LL
{
    while(p != NULL)    // p->next != NULL doesn't print the last element
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}


// duplicates() function to remove duplicates in a sorted LL
void RemoveDuplicates(struct Node *p)
{
    struct Node *q;
    q = p->next;   // p is a tail ptr to q
    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }

        else
        {
            p->next = q->next;
            delete q;    // 
            q = p->next;
        }
    }
}


int main()
{
    int A[] = {2,2,2,2};
    create(A,4);  // 5 is the number of elements in the array
    display(first);

    RemoveDuplicates(first);
    display(first);

    return 0;
}