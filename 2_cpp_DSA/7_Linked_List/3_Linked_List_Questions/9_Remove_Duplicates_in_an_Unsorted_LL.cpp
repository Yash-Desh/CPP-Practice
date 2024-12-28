// Author : Yash Deshpande
// Date : 15-10-2022
// Tutor : Love Babbar, Abdul Bari

#include <bits/stdc++.h>
#include <unordered_set>
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



// Approach -1 : Brute Force, TLE
// TC = O(N^2)
// SC = O(1)

Node *removeDuplicates(Node *head)
{
    // Write your code here
    if (head == NULL)
        return head;

    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current->next;
        Node *prevTemp = current;
        while (temp != NULL)
        {
            if (current->data == temp->data)
            {
                Node *nodeToDelete = temp;
                prevTemp->next = temp->next;
                temp = temp->next;
                delete nodeToDelete;
            }
            else
            {
                prevTemp = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
    return head;
}


// Approach - 2 : Better 
// TC : O(N*logN)
// SC : O(1)

// Step-1 : Sort the LL
// Step-2 : Apply "Remove Duplicates in a sorted LL Algorithm"


// Approach - 3 : Hashing
// TC : O(N)
// SC : O(N)

Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head == NULL)
        return head;
    
    unordered_set <int> hash;
    Node *current = head;
    Node *prev = NULL;
    while(current != NULL)
    {
        if(hash.find(current->data) != hash.end())
        {
            // Duplicate Element
            Node * nodeToDelete = current;
            prev->next = current->next;
            current = current->next;
            delete nodeToDelete;
        }
        else
        {
            // Not Duplicate Element
            hash.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
    return head;
}



int main()
{

    return 0;
}