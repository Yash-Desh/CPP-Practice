// Author : Yash Deshpande
// Date : 29-07-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

struct Node
{
    int data; // node data 
    struct Node *next;  // pointer to next node
}*Head;   // Head is a global pointer of the "Node type"


// function to create a circular LL from an array
void create (int A[], int n)  // A is a pointer to the array
{
    struct Node *t, *last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;   // circular LL 
    last = Head;   // head node is also the last node

    for(int i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    } 
}

// Iterative function to display circular LL
void display (Node *p)  // Takes input as the head of the CLL
{
    do
    {
       cout<<p->data<<" ";
       p = p->next;
    }while(p != Head);

    cout<<endl;
}


// function to calculate the number of elements in the CLL
int Length (Node *p)
{
    int len =0;
    do
    {
        len++;
        p = p->next;
    } while (p!=Head);
    return len;
}


// function to insert new element in a CLL
void insert(Node *p, int index, int x)  // p takes the head of the CLL as input
{
    // check if the index is valid
    if(index < 0 || index > Length(p))
    {
        return;
    }

    // for a valid index
    Node *t;
    // Case 1 : insert before the head
    if(index == 0)  
    {
        // create the new node
        t = new Node;
        t->data = x;
        
        // Case 1.1 : when CLL is empty
        if(Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else   // case 1.2 : when the CLL is NOT empty
        {
            while(p->next != Head)
            {
                p = p->next;
            }
            t->next = p->next;    // OR t->next = Head;
            p->next = t;
            Head = t;
        }
    }
    else  // insert after any given position
    {
        // create the new node
        t = new Node;
        t->data = x;

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
    int arr[] = {2,3,4,5,6};
    create(arr, 5);
    display(Head);

    insert(Head,17, 24);
    display(Head);
   

    return 0;
}