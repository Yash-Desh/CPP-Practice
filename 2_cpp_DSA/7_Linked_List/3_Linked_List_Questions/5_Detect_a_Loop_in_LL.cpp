// Author : Yash Deshpande
// Date : 14-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:

    // Approach - 1 : Using Map
    // TC : O(N)
    // SC : O(N)
    bool hasCycle(ListNode *head)
    {

        // Corner Case : when the LL has no node
        if (head == NULL)
        {
            return false;
        }

        map<ListNode *, bool> visited;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (visited[temp] == true)
                return true;

            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }



    // Approach -2 : Floyd's Cycle Detection Algo
    // TC : O(N)
    // SC : O(1)
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL)
        {
            fast = fast ->next;
            slow = slow->next;
            
            if(fast != NULL)
                fast = fast->next;

            if(fast == slow)
                return true;
        }
        return false;
    }
};


int main()
{

    return 0;
}