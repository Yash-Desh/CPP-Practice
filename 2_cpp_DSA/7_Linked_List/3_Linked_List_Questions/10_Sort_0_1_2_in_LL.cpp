// Author : Yash Deshpande
// Date : 16-10-2022
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

// Approach - 1 : Brute Force
// Count the number of 0s,1s,2s
// Sequentially insert them in LL

// TC = O(N)
// SC = O(1)

Node *sortList(Node *head)
{
    // Write your code here.
    int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == 0)
            cnt_0++;
        else if (p->data == 1)
            cnt_1++;
        else
            cnt_2++;

        p = p->next;
    }

    p = head;
    while (cnt_0--)
    {
        p->data = 0;
        p = p->next;
    }
    while (cnt_1--)
    {
        p->data = 1;
        p = p->next;
    }
    while (cnt_2--)
    {
        p->data = 2;
        p = p->next;
    }
    return head;
}

// #############################################
// Approach - 2 : Data replacement is not allowd
// Creating 3 seperate LLs 
// Creating dummy nodes containing -1 to avoid 
// complex if-else ladder when merging the 3 LLs

// TC = O(N)
// SC = O(1)
// #############################################

void insertAtTail (Node* &tail, Node *temp)
{
   tail->next = temp;
   tail = temp;
}

Node* sortList(Node *head)
{
    // Write your code here.
    
    // Approach - 2  : Data Replacement is not allowed
    
    // Creating 3 seperate LLS
    // creating dummy nodes
    Node *zeroHead = new Node (-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node (-1);
    Node *oneTail = oneHead; 
    Node *twoHead = new Node (-1);
    Node *twoTail = twoHead;
    
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
            insertAtTail(zeroTail, temp);
        
        else if(temp->data == 1)
            insertAtTail(oneTail , temp);
        
        else
            insertAtTail(twoTail , temp);
        
        temp = temp->next;
    }
    
    // Merging the 3 seperate LLs
    if(oneHead -> next != NULL)
    {
        zeroTail ->next = oneHead->next;
    }
    else
    {
        zeroTail ->next = twoHead->next;
    }
    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    
    // set up the head
    head = zeroHead->next;
    
    // delete the dummy nodes
    delete oneHead;
    delete zeroHead;
    delete twoHead;
    
    return head;
}


int main()
{

    return 0;
}