// Author : Yash Deshpande
// Date : 13-10-2022
// Tutor : Abdul Bari , Love Babbar

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Iterative Solution
// TC = O(N)
// SC = O(1)
Node *reverseLinkedList(Node *head)
{
    // Write your code here

    // Corner case : when LL has only 1 or no Node
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Recursive Solution-1
// TC = O(N)
// SC = O(N)
// Babbar Approach

// recursive function to reverse
// given SLL
void reverse(Node *&head, Node *curr, Node *prev)
{
    // Base Case
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

// function to call the recursive function
Node *reverseLinkedList(Node *head)
{
    // Write your code here
    Node *curr = head;
    Node *prev = NULL;
    reverse(head, curr, prev);
    return head;
}



// #####################
// Recursive Solution-2
// #####################
// TC = O(N)
// SC = O(N)
// Babbar approach
Node *reverseLinkedList(Node *head)
{
    // Write your code here
    // Base Case
    if (head == NULL || head->next == NULL)
        return head;


    // revHead now stores the head of the reversed LL not
    // containing the current head node
    Node *revHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return revHead;
}

// ######################
// Recursive Solution - 3
// ######################
// TC = O(N)
// SC = O(N)
struct Node *solve(Node *prev, Node *temp, Node *forward)
{
    if (forward == NULL)
        return temp;

    Node *ans = solve(temp, forward, forward->next);
    temp->next = prev;
    forward->next = temp;

    return ans;
}

// Function to reverse a linked list.
struct Node *reverseList(struct Node *head)
{
    // code here
    Node *prev = NULL;
    Node *temp = head;
    Node *forward = head->next;

    Node *ans = solve(prev, temp, forward);
    // return head of reversed list
    return ans;
}

int main()
{

    return 0;
}