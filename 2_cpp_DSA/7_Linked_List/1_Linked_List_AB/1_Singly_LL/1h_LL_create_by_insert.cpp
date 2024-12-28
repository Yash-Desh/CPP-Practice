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


// insert() function
void insert (struct Node *p,int index, int val)
{
    Node *t;  // Node type pointer to create new nodes
    
    // Check validity of the given index
    if(index < 0 || index > count(p))
    {
        return;
    }

    // creating the new node
    t = new Node;
    t->data = val;
    t->next = NULL;

    // insert at first position 
    if(index == 0)
    {
        t->next = first;
        first = t;
    }

    // insert after the given index
    else
    {
        for(int i=0; i<index-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}


int main()
{

    // insert at first position 
    insert(first, 0, 1);
    display(first);

    // insert after the given index
    insert(first, 1, 44);
    display(first);

    // insert after the given index
    insert(first, 2, 63);
    display(first);

    // insert after the given index
    insert(first, 0, 77);
    display(first);

    // insert at invalid index
    insert(first, 17, 85);
    display(first);
    
    return 0;
}