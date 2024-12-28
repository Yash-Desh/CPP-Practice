// Author : Yash Deshpande
// Date : 06-08-2023
// Tutor : Love Babbar(HW)

#include <bits/stdc++.h>
using namespace std;

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

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

// My Approach : AC
// TC : O(N)
// SC : O(1)
#include <bits/stdc++.h>
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here

    // count the nodes 
    int cnt = 1;
    Node *temp = head->next;
    while (temp != head)
    {
        cnt++;
        temp = temp->next;
    }

    // determine the half
    int half = ceil(float(cnt) / 2.0);

    // traverse the 1st half of the CSLL
    temp = head;
    *head1_ref = head;
    for (int i = 0; i < half - 1; i++)
    {
        temp = temp->next;
    }

    
    *head2_ref = temp->next;
    temp->next = head;
    temp = *head2_ref;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = *head2_ref;
}


// Method - 2 
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    
    // Using hare-tortoise approach
    Node *slow = head;
    Node *fast = head;
    
    do
    {
        fast = fast->next;
        if(fast->next != head)
        {
            fast = fast = fast->next;
            slow = slow->next;
        }
            
    }
    while(fast->next != head);
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = *head1_ref;
    fast->next = *head2_ref;
    
    
}

int main()
{

    return 0;
}