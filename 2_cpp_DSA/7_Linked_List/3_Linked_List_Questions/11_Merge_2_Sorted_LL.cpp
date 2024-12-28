// Author : Yash Deshpande
// Date : 16-10-2022
// Tutor : Love Babbar

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

// ##########################################################
// Approach -1 : Abdul Bari "merge 2 sorted arrays" technique
// My Approach : AC
// TC : O(N) ... where N = n+m
// SC : O(1)
// ##########################################################
void insertAtTail (Node <int>* &tail, Node <int> *temp)
{
    tail->next = temp;
    tail = temp;
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node <int>* head = new Node <int> (-1);
    Node <int>* tail = head;
    
    Node <int>*p1 = first;
    Node <int>*p2 = second;
    
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data < p2->data)
        {
            insertAtTail(tail, p1);
            p1 = p1->next;
        }
        else
        {
            insertAtTail(tail, p2);
            p2 = p2->next;
        }
    }
    while(p1 != NULL)
    {
        insertAtTail(tail, p1);
        p1 = p1->next;
    }
    
    while(p2 != NULL)
    {
        insertAtTail(tail, p2);
        p2 = p2->next;
    }
    
    // Deleting the dummy node
    Node <int>* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;

    // Return head of the resultant LLs
    return head;
}


// ##############################
// Approach - 2 : Babbar Approach
// ##############################
Node<int>* solve (Node<int>* first, Node<int>* second)
{
    // Corner Case : Only one element present in the "first" LL
    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }
    
    Node <int>* currf = first;
    Node <int>* nextf = first->next;
    
    Node <int>* currs = second;
    Node <int>* nexts = second->next;
    
    while(nextf != NULL && currs != NULL)
    {
        if(currf->data <= currs->data && nextf->data >= currs->data)
        {
            // add node in between the 1st list
            nexts = currs->next;
            currs->next = currf->next;
            currf->next = currs;
            
            // update the pointers
            currf = currs;
            currs = nexts;
        }
        else
        {
            currf = nextf;
            nextf = nextf->next;
            if(nextf == NULL)
            {
                currf->next = currs;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    
    // Corner Cases
    // when "first" list empty
    if(first == NULL)
        return second;
    
    // when "second" list empty
    if (second == NULL)
        return first;
    
    // Determine the LL with the smallest element
    if (first->data <= second->data)
        return solve (first, second);
    else
        return solve(second, first);
}



int main()
{

    return 0;
}