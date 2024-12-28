// Author : Yash Deshpande
// Date : 14-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Note 
// There is a difference in finding if a LL is circular 
// & detecting a loop in a LL

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

// Approach -1 : WA
// This approach doesn't handle
// inter-list loops
// TC = O(N)
// SC = O(1)
bool isCircular(Node *head)
{
    // Write your code here.

    // Corner Case : when CLL has no nodes
    if (head == NULL)
    {
        return 1;
    }

    Node *temp = head;
    do
    {
        temp = temp->next;
    } while (temp != NULL && temp != head);

    if (temp == NULL)
        return 0;

    else
        return 1;
}



// Approach-2 : Using map , TLE
// TC = O(N)
// SC = O(N)
bool isCircular(Node *head)
{
    // Write your code here.
    
    // Corner Case : when the LL has no node
        if (head == NULL)
        {
            return false;
        }

        map<Node *, bool> visited;
        Node *temp = head;
        while (temp != NULL)
        {
            if (visited[temp] == true)
                return true;

            visited[temp] = true;
            temp = temp->next;
        }
        return false;
}



// Approach - 3 : 2-pointer Approach
// TC = O(N)
// SC = O(1) 
bool isCircular(Node* head){
    // Write your code here.
    if(head == NULL)
        return 1;
    
    // 1 or more nodes
    Node *slow = head;
    Node *fast = head->next;
    while(fast != NULL && fast != slow && fast != head)
    {
        fast = fast->next;
        slow = slow->next;
        if(fast != NULL && fast != head)
            fast = fast ->next;
    }
    if(fast == head)
        return 1;
    else
        return 0;
}

int main()
{

    return 0;
}