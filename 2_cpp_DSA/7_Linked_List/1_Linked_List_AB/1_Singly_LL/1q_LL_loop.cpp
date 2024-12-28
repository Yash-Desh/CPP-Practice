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
    cout<<endl;
}

// function to check whether a given LL is loop
int isLoop (Node *f)
{
    Node *p, *q;
    p = q = f;
    do
    {
      p = p->next;
      q = q->next;
      if(q != NULL)
      {
        q = q->next;
      }  
    } while (p && q && p!=q);

    if( p == q )
    {
        return 1;
    }
    else 
    {
        return 0;
    }
    
}



int main()
{
    int A[] = {3,5,7,10,15};
    create(A,5);  // 5 is the number of elements in the array
    display(first);


    // creating a loop LL
    Node *t1,*t2 ;
    t1 = first->next->next;
    t2 = first->next->next->next->next;  // 15 is connected to 7
    t2->next = t1;

    cout<<isLoop(first)<<endl;
    return 0;
}