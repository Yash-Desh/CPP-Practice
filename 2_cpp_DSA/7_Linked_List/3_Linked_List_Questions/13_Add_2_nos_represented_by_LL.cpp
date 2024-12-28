// Author : Yash Deshpande
// Date : 20-10-2022
// Tutor : Love Babbar

#include <iostream>
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

// #################
// Only Approach
// TC : O(M+N)
// SC : O(max(M+N))
// #################

// // My Code : Unoptimized
// // Utility function to reverse a LL
// Node *reverse(Node *head)
// {
//     // Corner case
//     if (head->next == NULL)
//         return head;

//     Node *prev = NULL;
//     Node *current = head;
//     Node *forward = head->next;
//     while (current != NULL)
//     {
//         current->next = prev;
//         prev = current;
//         current = forward;
//         if (forward != NULL)
//             forward = forward->next;
//     }
//     return prev;
// }

// // Function to add two numbers represented by linked list.
// struct Node *addTwoLists(struct Node *first, struct Node *second)
// {
//     // code here
//     // My Appraoch :
//     // 1. Reverse both the linked lists
//     // 2. Add sum to a new LL
//     // 3. reverse the LL containing sum & return its head

//     // Step-1
//     Node *head1 = reverse(first);
//     Node *head2 = reverse(second);

//     // step-2
//     // new LL with dummy node created
//     Node *result = new Node(0);
//     Node *tail = result;
//     int carry = 0;
//     while (head1 != NULL && head2 != NULL)
//     {
//         int sum = head1->data + head2->data + carry;
//         int digit = sum % 10;
//         Node *temp = new Node(digit);
//         tail->next = temp;
//         tail = temp;
//         carry = sum / 10;
//         head1 = head1->next;
//         head2 = head2->next;
//     }

//     while (head1 != NULL)
//     {
//         int sum = head1->data + carry;
//         int digit = sum % 10;
//         Node *temp = new Node(digit);
//         tail->next = temp;
//         tail = temp;
//         carry = sum / 10;
//         head1 = head1->next;
//     }

//     while (head2 != NULL)
//     {
//         int sum = head2->data + carry;
//         int digit = sum % 10;
//         Node *temp = new Node(digit);
//         tail->next = temp;
//         tail = temp;
//         carry = sum / 10;
//         head2 = head2->next;
//     }

//     if (carry != 0)
//     {
//         Node *temp = new Node(carry);
//         tail->next = temp;
//         tail = temp;
//     }

//     // step - 3

//     Node *p = result;
//     result = result->next;
//     delete p;

//     return reverse(result);
// }

// ##################################
// Same Approach
// Better Code : Love Babbar Official
// ##################################

// Utility function to reverse a LL
    Node * reverse (Node *head)
    {
        // Corner case
        if(head->next == NULL)
            return head;
        
        Node *prev = NULL;
        Node *current = head;
        Node *forward = head->next;
        while(current != NULL)
        {
            current->next = prev;
            prev = current;
            current = forward;
            if(forward != NULL)
                forward = forward->next;
        }
        return prev;
    }
    
    // Utility function to insert at tail
    void insertAtTail (struct Node* &resultHead, struct Node* &tail, int digit)
    {
        Node *temp = new Node (digit);
        if(resultHead == NULL)
        {
            // Empty LL
            resultHead = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    
    // Utility function to add 
    Node * add (struct Node* head1, struct Node* head2)
    {
        int carry = 0;
        Node *resultHead = NULL;
        Node *tail = NULL;
        
        while(head1 != NULL || head2 != NULL || carry != 0)
        {
            int val1 = 0;
            if(head1 != NULL)
            {
                val1 = head1->data;
                head1 = head1->next;
            }
            
            int val2 = 0;
            if(head2 != NULL)
            {
                val2 = head2->data;
                head2 = head2->next;
            }
            
            int sum = val1 + val2 + carry;
            int digit = sum%10;
            carry = sum/10;
            
            insertAtTail (resultHead, tail, digit);
        }
        return resultHead;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        // 1. Reverse both the linked lists
        // 2. Add sum to a new LL
        // 3. reverse the LL containing sum & return its head
        
        // Step-1
        Node *head1 = reverse(first);
        Node *head2 = reverse(second);
        
        
        // step-2
        Node *result = add(head1, head2);
        
        return reverse(result);
        
    }

int main()
{

    return 0;
}