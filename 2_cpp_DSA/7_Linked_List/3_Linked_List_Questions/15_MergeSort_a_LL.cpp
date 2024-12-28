// Author : Yash Deshpande
// Date : 28-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


// Only Approach 


// Utility function to find the mid of the LL
node *findMid(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

// Utility function to merge 2 sorted LL
node *merge(node *left, node *right)
{
    node *resultHead = new node(0);
    node *resultTail = resultHead;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            resultTail->next = left;
            resultTail = left;
            left = left->next;
            resultTail->next = NULL;
        }
        else
        {
            resultTail->next = right;
            resultTail = right;
            right = right->next;
            resultTail->next = NULL;
        }
    }
    if (left != NULL)
        resultTail->next = left;
    if (right != NULL)
        resultTail->next = right;

    node *temp = resultHead;
    resultHead = resultHead->next;
    delete temp;
    return resultHead;
}


// Main Calling function
node *mergeSort(node *head)
{
    // Write your code here.
    // Base Case
    if (head == NULL || head->next == NULL)
        return head;

    // find the mid of the LL
    node *mid = findMid(head);
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // mergesort the left part
    left = mergeSort(left);
    // merge sort the right part
    right = mergeSort(right);

    // merge both the parts
    return merge(left, right);
}

int main()
{

    return 0;
}