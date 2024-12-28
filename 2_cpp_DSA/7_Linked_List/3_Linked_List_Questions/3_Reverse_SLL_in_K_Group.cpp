// Author : Yash Deshpande
// Date : 14-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
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


// #############################
// My Approach : Brute Force
// AC
// TC : O(N^2)
// SC : O(N)
// #############################


void arrayReversal (vector <int>&arr, int start, int end)
{
    while(start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }   
}
 

Node* kReverse(Node* head, int k) {
    // Write your code here.

    // copy all elements into the array
    vector <int> arr;
    Node *ptr = head;
    while(ptr != NULL)
    {
        arr.push_back(ptr->data);
        ptr = ptr->next;
    }

    // reverse each segment of arr individually
    
    for(int i=0; i<arr.size(); i= i+k)
    {
        int j = 0;
        if(i + (k-1) <= arr.size()-1)
        {
            j = i+k-1;
            arrayReversal(arr, i, j);
        }
    }

    ptr = head;
    for(int i=0; i<arr.size(); i++)
    {
        ptr->data = arr[i];
        ptr = ptr->next;
    }
    return head;
}





// Recursive Approach
// TC = O(N)
// SC = O(N)
Node *kReverse(Node *head, int k)
{
    // Write your code here.
    // Base Condition
    if (head == NULL)
        return NULL;

    // Reverse the K nodes
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    int cnt = k;
    while (cnt-- && curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    // Recursive Condition
    if (forward != NULL)
        head->next = kReverse(forward, k);

    // Return the head
    return prev;
}

int main()
{
    
}