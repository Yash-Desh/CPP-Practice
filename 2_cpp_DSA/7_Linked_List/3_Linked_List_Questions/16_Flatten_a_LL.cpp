// Author : Yash Deshpande
// Date : 28-10-2022
// Tutor : Love Babbar , Striver

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

// ##########################
// My Approach
// Approach - 1 : Brute Force
// AC 
// TC : N*K*log(K) 
// where N is the no of nodes in 
// the main LL and K is the avg no. 
// of nodes in a single sub-LL
// SC : O(N*K)
// ##########################

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    
    vector <int> v;
    Node* temp = head;
    while(temp != NULL)
    {
        Node* ptr = temp;
        while(ptr != NULL)
        {
            v.push_back(ptr->data);
            ptr = ptr->child;
        }
        temp = temp->next;
    }

    sort(v.begin(), v.end());

    Node* ans = new Node (-1);
    Node* tail = ans;
    for(int i=0; i<v.size(); i++)
    {
        tail->child = new Node(v[i]);
        tail = tail->child;
    }
    temp = ans;
    ans = ans->child;
    delete temp;
    return ans;
}


// Approach-2
// TC = O(N*N*M)    ->where N is the no of nodes in the main linked list and M is the no of nodes in a single sub-linked list 
// SC = O(1)
Node *merge (Node *first, Node *second )
{
    Node *ans = new Node (-1);
    Node *tail = ans;
    while(first != NULL && second != NULL)
    {
        if(first->data < second->data)
        {
            tail->child = first;
            tail = first;
            first = first->child;
        }
        else
        {
            tail->child = second;
            tail = second;
            second = second->child;
        }
    }
    if(first != NULL)
        tail->child = first;
    if (second != NULL)
        tail->child = second;
   
    Node *toDelete = ans;
    ans = ans->child;
    delete toDelete;
    return ans;
}


Node* flattenLinkedList(Node* head) 
{
	// Write your code here
 
    // Base Case 
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *vertical = head;
    Node *horizontal = flattenLinkedList(head->next);
    vertical->next = NULL;
    return merge(vertical , horizontal); 
    
}


int main()
{
    
    return 0;
}

