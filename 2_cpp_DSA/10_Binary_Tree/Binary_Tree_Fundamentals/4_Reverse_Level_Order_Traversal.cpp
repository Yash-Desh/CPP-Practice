// Name : Yash Deshpande
// Date : 18-04-2024
// Tutuor : Love Babbar [HW], code library YT
//
// NOTE : This file uses a function signature that returns a flat vector<int>.
//        A different (LeetCode style) function signature that returns
//        vector<vector<int>> (levels grouped separately, bottom-up) is covered in
//        4b_Level_Order_Traversal_II.cpp in the same directory.

#include <bits/stdc++.h>
using namespace std;


// ########################################
// Approach-1 : Brute Force
// Source : Code Library (https://youtu.be/t6IwIr8mPz0?si=nGvumKJr2WL7fCRy)
// TC : O(N)  -> N is the number of nodes
// SC : O(N)
// ########################################
struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    queue<Node *> q;

    // check if root is not NULL
    if (!root)
    {
        return ans;
    }

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        if (temp->right)
            q.push(temp->right);

        if (temp->left)
            q.push(temp->left);
    }


    // Reverse the vector
    reverse(ans.begin(), ans.end());
    return ans;
}

// ########################################
// Approach-2 : Optimal -> using stacks
// Source : GFG (https://www.geeksforgeeks.org/dsa/reverse-level-order-traversal/#expected-approach-using-stack-and-queue-on-time-and-on-space)
// TC : O(N)  -> N is the number of nodes
// SC : O(N)
// ########################################

vector<int> reverseLevelOrder_stack(Node *root) {
    // declarations
    vector<int> ans;
    queue<Node *> q;
    stack<Node *> st;

    // check if root is not NULL
    if (!root) {
        return ans;
    }

    q.push(root);

    // level-order while loop
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        st.push(temp);

        // Enqueue the right
        if (temp->right)
            q.push(temp->right);

        // Enqueue the left
        if (temp->left)
            q.push(temp->left);
    }

    // pop the stack to build the reversed level order
    while (!st.empty()) {
        ans.push_back(st.top()->data);
        st.pop();
    }

    return ans;
}


int main()
{

    return 0;
}