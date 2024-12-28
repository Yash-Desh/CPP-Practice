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

// Recursive function to display CLL
void Rdisplay (Node *p)
{
    static int flag = 0;   // static variable that keeps a count of how many times p = Head , if more than 0 , loop stops
    if(p != Head || flag ==0)
    {
        flag = 1;
        cout<<p->data<<" ";
        Rdisplay(p->next);
    }
    cout<<endl;
    flag = 0;  // static variable flag must be made 0 so that the function runs if it is called more than once in the program
}

int main()
{
    int arr[] = {2,3,4,5,6};
    create(arr, 5);
    Rdisplay(Head);
   

    return 0;
}