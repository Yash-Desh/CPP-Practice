// Author : Yash Deshpande
// Date : 31-07-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;


// structure Node for a doubly linked LL
struct Node 
{
    struct Node *prev;  // pointer to previous node
    int data;  //  // node data 
    struct Node *next;   // pointer to next node
}*head = NULL;   // "first" is a global pointer of the "Node type" , initialized to point at nothing


// function to create a Circular DLL from an array
void create (int A[], int n)  // n = number of elements in the array
{
    struct Node *t;  // Temporary pointer of node type to help create new nodes
    struct Node *last;  // ptr to the last node in the LL , to help attach new nodes after the last node  

    // to create the "first node"
    head = new Node;
    head->data = A[0];
    head->prev = head;
    head->next = head;
    last = head;

    // to create the remaining nodes
    for(int i=1; i<n; i++)
    {
        // create the new node
        t = new Node;
        t->data =A[i];
        t->next = head;
        t->prev = last;  // connect the new node to the DLL

        head->prev = t;
        last->next = t;
        last = t;
    }
}


// function to display a DLL
void display (Node *p)
{
    do
    {
       cout<<p->data<<" ";
       p=p->next;  
    }while (p != head);
    cout<<endl;
}


// function to calculate the number of elements of DLL
int Length (Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    }while(p != head);
    return len;
}



// function to insert new node in a CDLL
void insert (Node *p, int index, int x)
{

}


int main()
{
    int A[] = {3,5,7,10,15,98};
    create(A,6);  // 5 is the number of elements in the array
    display(head);
    cout<<"Number of elements in the CDLL "<<Length(head)<<endl;

    return 0;
}