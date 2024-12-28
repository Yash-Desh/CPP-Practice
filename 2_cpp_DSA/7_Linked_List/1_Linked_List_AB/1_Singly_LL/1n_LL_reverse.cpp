// Author : Yash Deshpande 
// Date : 27-07-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

// structure to define a Node
struct Node
{
    int data;    // node data 
    struct Node *next;   // pointer to next node
}*first = NULL;   // "first" is a global pointer of the "Node type" , initialized to point at nothing


// function to create a LL from an array
void create(int Arr[], int n)  // n = number of elements in the array
{
    
    struct Node *t;  // Temporary pointer of node type to help create new nodes
    struct Node *last;  // ptr to the last node in the LL , to help attach new nodes after the last node

    // Creating the 1st(head) node
    first = new Node;
    first->data = Arr[0];
    first->next = NULL;
    last = first;  // LL contains only 1 node , thus first node is the last node

    // Creating the remaining nodes
    for(int i=1; i<n; i++)    // i = 1 bcuz the 1st node is already created using Arr[0]
    {
        // t creates a new node
        t = new Node;  
        t->data = Arr[i];
        t->next = NULL;

        // Attaching the new node to the back of the last node of the LL
        last->next = t;
        last = t;   //new node is now the last node 
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


// Iterative function to find number of elements / length of a Linked list
int count (struct Node *p)
{
    int cnt = 0;
    while(p)
    {
        cnt++;
        p = p->next;  
    }
    return cnt;
}


// reverse() function to reverse the elements using auxillary array
void reverse (struct Node *p)
{
    int *A;   // dynamic array
    A = new int [count(p)];   // auxillary array osf the same size as the length of the LL
    int i=0;    // index counter for the auxillary array
    Node *q = p;   // Node type pointer to traverse the LL

    // Loop to copy LL contents into auxillary array
    while(q != NULL)
    {
        A[i++] = q->data;
        q = q->next; 
    }

    i--;
    q = p;

    // Loop to reverse copy the array elements into the LL
    while(q != NULL)
    {
        q->data = A[i--];
        q = q->next; 
    }
}


// reverseLinks() function to reverse the links of the LL
void reverseLinks (Node *p)
{
    Node *q =NULL, *r=NULL;
    while(p != NULL)
    {
        r = q;       // sliding pointer mechanism
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;       // first points to the new head of the linklist
}


// revRecursive() is a Recursive function to reverse the LL
void revRecursive (struct Node *q, Node *p)
{
    if( p != NULL)
    {
        revRecursive(p, p->next);   // head recursion
        p->next = q;    // reversing links @ returning time
    }
    else
    {
        first = q;    // last of the LL is set as first
    }
}

int main()
{
    int A[] = {3,56,77,10,15};
    create(A,5);  // 5 is the number of elements in the array
    display(first);

    // reverse(first);
    // display(first);

    // reverseLinks(first);
    // display(first);

    revRecursive(NULL, first);
    display(first);

    return 0;
}