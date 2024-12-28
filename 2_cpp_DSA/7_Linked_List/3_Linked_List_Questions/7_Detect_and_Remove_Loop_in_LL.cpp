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


// ############
// Method - 2 
// Map Method
// TC : O(N)
// SC : O(N)
// ############



Node *removeLoop(Node *head)
{
    // Write your code here.
    // step-1 :  floyd's cycle detection algo
    if(head == NULL)
        return NULL;
    
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
        if(fast != NULL)
            fast = fast->next;
        
        if(fast == slow)
            break;
    }
    
    if(fast == NULL)
        return head;
    
    Node *intersection = fast;
    slow = head;
    
    while(slow != intersection)
    {
        intersection = intersection->next;
        slow = slow->next;
    }
    
    Node *temp = intersection->next;
    while(temp->next != intersection)
        temp = temp->next;
    
    temp->next = NULL;
    return head;
}

/*
Love Babbar's in-video Method

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}
*/
int main()
{

    return 0;
}