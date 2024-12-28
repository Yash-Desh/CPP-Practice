// Author : Yash Deshpande
// Date : 29-07-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

// "Node" class with 2 public data members, used to create a node
class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
    Node *first;

public:
    // Default constructor that makes "first" point to NULL
    LinkedList() { first = NULL; }

    // Parameterized constructor that takes an array and creates a LL
    LinkedList(int *arr, int n);

    // destructor
    ~LinkedList();

    void display();
    void insert(int x, int index);
    int Delete(int index);
    int length();
};

LinkedList ::LinkedList(int arr[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

LinkedList ::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList ::display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int LinkedList ::length()
{
    Node *p = first;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList ::insert(int x, int index)
{
    if (index < 0 || index > length())
    {
        return;
    }
    else
    {
        Node *p = first;
       
        Node *t = new Node;
        t->data = x;
        t->next = NULL;
        
        if (index == 0)
        {
            t->next = first;
            first = t;
        }

        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
}

int LinkedList ::Delete(int index)
{
    Node *p = first;
    Node *q = NULL; // tail pointer to main ptr p
    int x = -1;     // stores & returns the data of the deleted node

    // check for validity of the index
    if (index < 1 || index > length())
    {
        return -1;
    }

    // if first node is to be deleted
    if (index == 1)
    {
        first = p->next;
        x = p->data;
        delete p;
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int main()
{
    int A[] = {1,2,3,4,5};
    LinkedList l1(A,5);

    // cout<<l1.Delete(3)<<endl;
    l1.insert(13,0);
    l1.display();
    return 0;
}