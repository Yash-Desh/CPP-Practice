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
}*first = NULL;   // first is a global pointer of the "Node type" , initialized to point at nothing

// function to create a LL from an array
void create(int Arr[], int n)  // n = number of elements in the array
{
    
    struct Node *t;  // Temporary pointer of node type to help create new nodes
    struct Node *last;  // ptr to the last node in the LL , to help add new nodes after the last node

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

// Recursive function to find number of elements / length of a Linked list
int Rcount (struct Node *p)
{
    if(p != NULL)
    {
        return Rcount(p->next) + 1;  // Addition at returning time
    }
    else
    {
        return 0;
    }
}


int main()
{
    int A[] = {3,5,7,10,15};
    create(A,5);
    //display(first);

    cout<<"Length of Linked List = "<<count(first)<<endl;
    cout<<"Length of Linked List = "<<Rcount(first)<<endl;

    return 0;
}