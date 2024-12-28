// Author : Yash Deshpande
// Date : 18-10-2022
// Tutor : Love Babbar

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


// ##########################################
// Approach - 1
// Brute Force : Using a seperate array , AC
// TC : O(N)
// SC : O(N)
// ##########################################

// Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    // Your code here
    vector<int> copy;
    Node *temp = head;
    while (temp != NULL)
    {
        copy.push_back(temp->data);
        temp = temp->next;
    }

    for (int i = 0; i < copy.size() / 2; i++)
    {
        if (copy[i] != copy[copy.size() - i - 1])
            return 0;
    }
    return 1;
}

// ###############################
// Approach -2 
// creating a copy of the given LL
// reversing it
// Compare it with the original LL
// TC : O(N)
// SC : O(N)
// ################################


// #####################
// Optimal Approach : AC
// TC : O(N)
// SC : O(1)
// #####################

// function to find the middle of a linked List
    // & returns the middle of the linked list
    Node * findMiddle (Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        
        while( fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
  
    
    // Function to reverse a LL
    Node * reverse(Node *head)
    {
        // corner case
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        Node *prev = NULL;
        Node *temp = head;
        Node *forward = head->next;
        
        while(temp != NULL)
        {
            temp->next = prev;
            prev = temp;
            temp = forward;
            if(forward != NULL)
                forward = forward->next;
        }
        return prev;
    }
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        // 1. find the middle of the LL
        // 2. reverse the 2nd half
        // 3. compare the 2 halves simultaneously
        // 4. Optional : reverse the 2nd half again to get the
        //    original LL
        
        // Corner Case : when the LL has no nodes or only 1 node
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        
        // Step - 1 : find middle of LL
        Node *middle = findMiddle(head);
        
        // Step - 2 : reverse the 2nd half of LL
        Node *temp = middle->next;
        middle->next = reverse(temp);
        
        // Step - 3 : compare the 2 parts
        
        Node *head1 = head;
        Node *head2 = middle->next;
        while(head2 != NULL)
        {
            if(head1->data != head2->data)
                return false;
                
            head1 = head1->next ;
            head2 = head2->next;
        }
        
        // step-4 (OPTIONAL): Repeat step 2 
        temp = middle->next;
        middle->next = reverse(temp);
        
        return true;
    }

int main()
{

    return 0;
}