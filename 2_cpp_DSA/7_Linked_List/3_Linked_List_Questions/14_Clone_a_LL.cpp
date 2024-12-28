// Author : Yash Deshpande
// Date : 27-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

// ##############################
// My Approach
// Approach-1 : AC , Brute Force
// TC : O(N^2)
// SC : O(1)
// ##############################
Node *copyList(Node *head)
{
    // Write your code here
    // Step-1 : Create a clone list using
    //          next pointer
    Node *copyHead = NULL;
    Node *temp1 = head;
    Node *tail = copyHead;
    while (temp1 != NULL)
    {
        // when the new LL is empty
        if (copyHead == NULL)
        {
            Node *temp2 = new Node(temp1->data);
            copyHead = temp2;
            tail = temp2;
        }
        else
        {
            Node *temp2 = new Node(temp1->data);
            tail->next = temp2;
            tail = temp2;
        }
        temp1 = temp1->next;
    }

    // Complete the clone list by using arb
    // pointer with nested loops
    temp1 = head;
    Node *temp2 = copyHead;
    while (temp1 != NULL)
    {
        Node *ptr1 = head;
        Node *ptr2 = copyHead;
        while (ptr1 != temp1->arb && ptr1 != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        temp2->arb = ptr2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return copyHead;
}

// ############################
// Approach-2 : Using a mapping
// Babbar Approach
// TC : O(N)
// SC : O(N)
// ############################
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *copyList(Node *head)
{
    // Write your code here

    // Step-1: create a clone node
    Node *p = head;
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    while (p != NULL)
    {
        insertAtTail(cloneHead, cloneTail, p->data);
        p = p->next;
    }

    // Step-2: create a mapping

    unordered_map<Node *, Node *> oldToNew;

    Node *originalNode = head;
    Node *cloneNode = cloneHead;
    while (originalNode != NULL)
    {
        oldToNew[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // Step-3 : Use the mapping to connect arb
    originalNode = head;
    cloneNode = cloneHead;
    while (originalNode != NULL)
    {
        cloneNode->arb = oldToNew[originalNode->arb];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

// Approach-3
// TC : O(N)
// SC : O(1)
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}


Node *copyList(Node *head)
{
    // Write your code here

    // Step-1: create a clone node
    Node *p = head;
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    while (p != NULL)
    {
        insertAtTail(cloneHead, cloneTail, p->data);
        p = p->next;
    }

    // Step-2: inserting clone nodes into original LL
    Node *cloneNode = cloneHead;
    Node *originalNode = head;
    while (originalNode != NULL && cloneNode != NULL)
    {
        // for the original LL
        Node *originalForward = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = originalForward;

        // for the clone LL
        Node *cloneForward = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = cloneForward;
    }

    // step-3 connect the arb nodes
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->arb != NULL)
        {
            temp->next->arb = temp->arb->next;
        }
        temp = temp->next->next;
    }

    // step-4 : revert the changes made in step-2
    cloneNode = cloneHead;
    originalNode = head;
    while (originalNode != NULL)
    {
        Node *originalForward = cloneNode->next;
        originalNode->next = originalForward;
        originalNode = originalForward;

        // for the clone LL
        if (originalNode != NULL)
        {
            Node *cloneForward = originalNode->next;
            cloneNode->next = cloneForward;
            cloneNode = cloneForward;
        }
    }

    return cloneHead;
}

int main()
{

    return 0;
}
