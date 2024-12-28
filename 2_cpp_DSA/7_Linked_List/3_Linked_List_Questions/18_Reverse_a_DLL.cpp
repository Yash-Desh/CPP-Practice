// Author : Yash Deshpande
// Date : 13-10-2022
// Tutor : Abdul Bari , Love Babbar

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// Iterative Approach : My Approach
// TC : O(N)
// SC : O(1)
// AC
Node *reverseDLL(Node *head)
{
    // Your code here
    if (head == NULL || head->next == NULL)
        return head;

    Node *current = head;
    Node *previous = NULL;
    Node *forward = NULL;

    while (current != NULL)
    {
        forward = current->next;
        current->prev = current->next;
        current->next = previous;
        previous = current;
        current = forward;  
    }
    return previous;
}

int main()
{

    return 0;
}