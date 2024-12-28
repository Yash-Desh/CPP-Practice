// Author : Yash Deshpande
// Date : 15-10-2022
// Tutor : Love Babbar, Abdul Bari

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Approach -1 : 2 Pointer Method , AC
// TC = O(N)
// SC = O(1)
Node *uniqueSortedList(Node *head)
{
    // Write your code here.
    // Corner Case
    if (head == NULL || head->next == NULL)
        return head;

    Node *current = head;
    Node *forward = head->next;
    while (forward != NULL)
    {
        if (forward->data == current->data)
        {
            current->next = forward->next;
            Node *nodeToDelete = forward;
            forward = forward->next;
            delete nodeToDelete;
        }
        else
        {
            current = forward;
            forward = forward->next;
        }
    }
    return head;
}

// Approach - 2 : 1-Pointer Method, AC
// TC = O(N)
// SC = O(1)
Node *uniqueSortedList(Node *head)
{
    // Write your code here.
    if (head == NULL)
        return head;

    Node *current = head;
    while (current != NULL)
    {
        if ((current->next != NULL) && (current->data == current->next->data))
        {
            Node *nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}

int main()
{

    return 0;
}