// Author : Yash Deshpande
// Date : 27-07-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

// structure to define a Node
struct Node
{
    int data;                                   // node data
    struct Node *next;                          // pointer to next node
} *first = NULL, *second = NULL, *third = NULL; // "first" is a global pointer of the "Node type" , initialized to point at nothing

// function to create a LL from an array
void create(int Arr[], int n) // n = number of elements in the array
{

    struct Node *t;    // Temporary pointer of node type to help create new nodes
    struct Node *last; // ptr to the last node in the LL , to help attach new nodes after the last node

    // Creating the 1st(head) node
    first = new Node;
    first->data = Arr[0];
    first->next = NULL;
    last = first; // LL contains only 1 node , thus first node is the last node

    // Creating the remaining nodes
    for (int i = 1; i < n; i++) // i = 1 bcuz the 1st node is already created using Arr[0]
    {
        // t creates a new node
        t = new Node;
        t->data = Arr[i];
        t->next = NULL;

        // Attaching the new node to the back of the last node of the LL
        last->next = t;
        last = t; // new node is now the last node
    }
}

// function to create a LL from an array
void create2(int Arr[], int n) // n = number of elements in the array
{

    struct Node *t;    // Temporary pointer of node type to help create new nodes
    struct Node *last; // ptr to the last node in the LL , to help attach new nodes after the last node

    // Creating the 1st(head) node
    second = new Node;
    second->data = Arr[0];
    second->next = NULL;
    last = second; // LL contains only 1 node , thus first node is the last node

    // Creating the remaining nodes
    for (int i = 1; i < n; i++) // i = 1 bcuz the 1st node is already created using Arr[0]
    {
        // t creates a new node
        t = new Node;
        t->data = Arr[i];
        t->next = NULL;

        // Attaching the new node to the back of the last node of the LL
        last->next = t;
        last = t; // new node is now the last node
    }
}

// display() function
void display(struct Node *p) // p is a "Node type" pointer that traverses the LL
{
    while (p != NULL) // p->next != NULL doesn't print the last element
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// merge() function to merge to sorted LL
void merge(struct Node *p, Node *q)
{
    Node *last = NULL; // Node type pointer to attach new nodes to the back of the new merged LL
    // code block to create the head of the merged LL i.e "third"
    if (p->data < q->data)
    {
        third = p;
        last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = q;
        last = q;
        q = q->next;
        last->next = NULL;
    }

    // code block to create the rest of the merged LL till one of the 'p' or 'q' reaches NULL
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p != NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
}

int main()
{
    int A[] = {310, 560, 780, 1010, 1050};
    create(A, 5); // 5 is the number of elements in the array
    display(first);

    int B[] = {32, 52, 57, 108, 156};
    create2(B, 5); // 5 is the number of elements in the array
    display(second);


    merge(first, second);
    display(third);
    return 0;
}