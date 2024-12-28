// Author : Yash Deshpande
// Date : 04-02-2023
// Tutor : Abdul Bari

#include <bits/stdc++.h>
using namespace std;

// structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Should return head of the modified linked list
Node *sortedInsert(struct Node *head, int data)
{
    // Code here

    Node *temp = new Node(data);

    // if LL is empty
    if (head == NULL)
    {
        head = temp;
    }

    else
    {
        Node *current = head;
        Node *prev = NULL;
        while (current != NULL && data > current->data)
        {
            prev = current;
            current = current->next;
        }

        if (current == head)
        {
            temp->next = current;
            head = temp;
        }
        else
        {
            temp->next = current;
            prev->next = temp;
        }
    }

    return head;
}

int main()
{

    return 0;
}