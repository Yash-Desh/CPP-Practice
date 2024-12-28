// Author : Yash Deshpande
// Date : 23-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

// structure to define a Node
struct Node
{
    int data;          // node data
    struct Node *next; // pointer to next node
} *first = NULL;       // "first" is a global pointer of the "Node type" , initialized to point at nothing

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

// SortInsert() to insert elements in a sorted LL
void SortedInsert(struct Node *p, int val)
{
    struct Node *t, *q = NULL; // t = ptr to create new nodes   ,   q = "tail ptr" to main ptr p

    // creating the new node
    t = new Node;
    t->data = val;
    t->next = NULL;

    // check if the LL is empty
    if (first == NULL)
    {
        first = t;
    }
    else // runs when the LL is not empty
    {
        while (p && val > p->data )   // NOTE :: some error occurs if we give (val>p->data && p)
        {
            q = p;
            p = p->next;
        }

        // check if given val is smaller than the smallest element in the LL
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5); // 5 is the number of elements in the array
    display(first);

    // inserting in non-empty list
    SortedInsert(first, 55);
    display(first);

    // // inserting in an empty list
    // SortedInsert(first, 45);
    // display(first);

    // SortedInsert(first, 5);
    // display(first);

    SortedInsert(first, 67);
    display(first);

    return 0;
}

/*

##############################################Extra Notes#####################################################


What is the difference is "(p && val > p->data)"  and  "(val > p->data && p)"  ? 

*/