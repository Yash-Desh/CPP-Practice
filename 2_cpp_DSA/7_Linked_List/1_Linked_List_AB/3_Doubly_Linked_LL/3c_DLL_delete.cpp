// Author : Yash Deshpande
// Date : 30-07-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;


// structure Node for a doubly linked LL
struct Node 
{
    struct Node *prev;  // pointer to previous node
    int data;  //  // node data 
    struct Node *next;   // pointer to next node
}*first = NULL;   // "first" is a global pointer of the "Node type" , initialized to point at nothing


// function to create a DLL from an array
void create (int A[], int n)  // n = number of elements in the array
{
    struct Node *t;  // Temporary pointer of node type to help create new nodes
    struct Node *last;  // ptr to the last node in the LL , to help attach new nodes after the last node  

    // to create the "first node"
    first = new Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    // to create the remaining nodes
    for(int i=1; i<n; i++)
    {
        // create the new node
        t = new Node;
        t->data =A[i];
        t->next = NULL;
        t->prev = last;  // connect the new node to the DLL
        last->next = t;
        last = t;
    }
}


// function to display a DLL
void display (Node *p)
{
    while(p != NULL)
    {
       cout<<p->data<<" ";
       p=p->next;  
    }
    cout<<endl;
}


// function to calculate the number of elements of DLL
int Length (Node *p)
{
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}


// function to delete node in DLL
int Delete (Node *p, int index)
{
    int x;  // variable to store deleted data
    if(index <1 || index > Length(p))
    {
        return -1;
    }

    if(index == 1)
    {
        x = first->data;
        first = first->next;
        if(first)   // when DLL consists more than 1 nodes
        {
             first->prev = NULL;
        }
        delete p;
    }

    else{
        for(int i=0; i<index-1; i++)
        {
            p=p->next;
        }
        x = p->data;
        p->prev->next = p->next;
        if(p->next)    // when new node is NOT inserted at the very end of the DLL
        {
            p->next->prev = p->prev;
        }
        delete p;
    }
    return x;
}

int main()
{
    int A[] = {3,5,7,10,15,98};
    create(A,6);  // 5 is the number of elements in the array
    display(first);
    
    cout<<"Deleted element is "<<Delete(first, 5)<<endl;
    display(first);

    return 0;
}