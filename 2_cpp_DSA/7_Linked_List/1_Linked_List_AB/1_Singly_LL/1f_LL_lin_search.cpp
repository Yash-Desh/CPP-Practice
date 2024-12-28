// Author : Yash Deshpande 
// Date : 23-06-2022
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
}


// Iterative Function to find the element using Linear Search
struct Node* LinSearch (struct Node *p , int key)
{
    while(p != NULL)
    {
        if(p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Recursive function to find the element using Linear Search
Node * RLinSearch (Node *p , int key)
{
    if(p == NULL)
    {
        return NULL;
    }
    else if(p->data == key)
    {
        return p;
    }
    else
    {
        return RLinSearch(p->next,key);
    }
}


// Improved Linear Search using "Move to head" method "Iteratively"
Node* ImprovedLinSearch (Node *p, int key)
{
    Node *q =NULL;
    while( p != NULL)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}


int main()
{
    int A[] = {3,5,71,10,15,24,45,53,77};
    create(A,9);
    display(first);

    struct Node *temp = ImprovedLinSearch(first, 24);
    if(temp)
    {
        cout<<"\nkey is found "<<temp->data<<endl;
    }
    else
    {
        cout<<"\nkey not found"<<endl;
    }
    display(first);

    return 0;
}