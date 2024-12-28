// Author : Yash Deshpande
// Date : 30-07-2022
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


// function to delete the element at the given index
int Delete (Node *p, int index)
{
    if(index < 0 || index > Length(p))
    {
        return -1;
    }

    Node *q;
    int x;

    // To delete Head node
    if(index == 1)
    {
        // Loop to reach the last node of the CLL
        while(p->next != Head)
        {
            p=p->next;
        }
        x = Head->data;    // copy node to be deleted data into separate variable

        // if the CLL has only 1 node
        if(p == Head)
        {
            delete Head;
            Head = NULL;
        }

        // if the CLL has more than 1 nodes
        else
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
            
        }
        
    }

    // To delete node after any node
    else
    {
        for(int i=0; i<index-2; i++)
        {
            p=p->next;   // p points to 1 node before the node to be deleted
        }
        q = p->next; // q points to the node to be deleted
        x = q->data;

        p->next = q->next;
        delete q;
    }
    return x;
}


int main()
{
    int arr[] = {2,3,4,5,6};
    create(arr, 5);
    display(Head);

    cout<<Delete(Head,1)<<endl;
    display(Head);
   

    return 0;
}