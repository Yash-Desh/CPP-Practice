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

// Brute Force Solution
// TC = O(N)
// SC = O(1)
int getLength(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *findMiddle(Node *head)
{
    // Write your code here
    int n = getLength(head);
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        head = head->next;
    }
    return head;
}

// Better Solution
// TC = O(N)
// SC = O(1)
Node *findMiddle(Node *head)
{
    // Write your code here

    // Corner Cases

    // if SLL is empty or has 1 node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // if SLL has 2 nodes
    else if (head->next->next == NULL)
    {
        return head->next;
    }

    // if SLL has 3 or more nodes
    else
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
}

int main()
{

    return 0;
}