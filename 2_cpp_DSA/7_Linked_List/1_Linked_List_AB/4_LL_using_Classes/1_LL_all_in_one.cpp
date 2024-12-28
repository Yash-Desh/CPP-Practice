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
}*first = NULL, *second = NULL, *third = NULL;   // first is a global pointer of the "Node type" , initialized to point at nothing

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


// function to create a LL from an array
void create2(int Arr[], int n)  // n = number of elements in the array
{
    
    struct Node *t;  // Temporary pointer of node type to help create new nodes
    struct Node *last;  // ptr to the last node in the LL , to help attach new nodes after the last node

    // Creating the 1st(head) node
    second = new Node;
    second->data = Arr[0];
    second->next = NULL;
    last = second;  // LL contains only 1 node , thus first node is the last node

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


// #1 display() function
void display(struct Node *p)   // p is a "Node type" pointer that traverses the LL
{
    while(p != NULL)    // p->next != NULL doesn't print the last element
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}


// #2 Recursive display() function with "Tail Recursion"
void rDisplayTail (struct Node *p)   // p is a "Node type" pointer that traverses the LL
{
    if(p != NULL)
    {
        cout<<p->data<<" ";
        rDisplayTail(p->next);
    }
}


// #3 Recursive display() function with "Head Recursion"
void rDisplayHead (struct Node *p)   // p is a "Node type" pointer that traverses the LL
{
    if(p != NULL)
    {
        rDisplayHead(p->next);
        cout<<p->data<<" ";
    }
}


// #4 Iterative function to find number of elements / length of a Linked list
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

// #5 Recursive function to find number of elements / length of a Linked list
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


// #6 Iterative function to find sum of all elements
int add (struct Node *p)
{
    int sum=0;
    while(p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}


// #7 Recursive function to find sum of all elements
int rAdd (struct Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        return rAdd(p->next) + p->data;
    }
}



// #8 Iterative function to find the maximum element

int max(struct Node *p)
{
    int max = INT_MIN;  // -32768
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

// #9 Recursive function to find maximum element
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


// #10 Iterative function to find the minimum element

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


// #11 Recursive function to find minimum element
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


// #12 Iterative Function to find the element using Linear Search
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

// #13 Recursive function to find the element using Linear Search
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


// #14 Improved Linear Search using "Move to head" method "Iteratively"
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

// #15 insert() function
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



// #####################################################################################

int main()
{
    int A[] = {3,5,7,10,15};
    create(A,5);
    display(first);

    return 0;
}