// Author : Yash Deshpande 
// Date : 28-06-2022
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

// Iterative function to find the maximum element

int max(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// Recursive function to find maximum element
int Rmax (struct Node *p)
{
    int x=0;
    if(p == NULL)
    {
        return INT32_MIN;
    }
    else
    {
        x = Rmax(p->next);
        if(p->data > x)
        {
            return p->data;
        }
        else
        {
            return x;
        }
    }
}


// Iterative function to find the minimum element

int min(struct Node *p)
{
    int min = INT_MAX;
    while(p)
    {
        if(p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}


// Recursive function to find minimum element
int Rmin(struct Node *p)
{
    int x=0;
    if(!p)
    {
        return INT32_MAX;
    }
    else
    {
        x = Rmin(p->next);
        if(x < p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}


int main()
{
    int A[] = {3,5,7,10,-15,12,17,2};
    create(A,8);
    // display(first);

    //cout<<"Maximum element is "<<max(first)<<endl;

    // cout<<"Maximum element is "<<Rmax(first)<<endl;

    // cout<<"Minimum element is "<<min(first)<<endl;

    cout<<"Minimum element is "<<Rmin(first)<<endl;

    return 0;
}