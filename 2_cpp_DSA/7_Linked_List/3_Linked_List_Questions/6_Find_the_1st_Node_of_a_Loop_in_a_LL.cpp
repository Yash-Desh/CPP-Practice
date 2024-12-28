// Author : Yash Deshpande
// Date : 14-10-2022
// Tutor : Love Babbar

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// #################################
// Method - 1 
// Floyd's cycle detection algorithm
// TC : O(N)
// SC : O(1)
// #################################

ListNode *detectCycle(ListNode *head)
{
    // corner case : when LL has no nodes
    if (head == NULL)
        return NULL;

    // step 1 : find point of intersection
    // b/w fast & slow

    // NOTE : It is very important that both
    // the fast & slow start from the head node
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *intersection = NULL;
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;

        if (fast != NULL)
            fast = fast->next;

        if (fast == slow)
        {
            intersection = fast;
            break;
        }
    }
    if (fast == NULL)
        return NULL;

    slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return intersection;
}




// ############
// Method - 2 
// Map Method
// TC : O(N)
// SC : O(N)
// ############

int main()
{

    return 0;
}