// Name : Yash Deshpande
// Date : 13-03-2025
// Tutuor : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// ######################################
// Using Level-Order Traversal
// Source : My Approach -> Accepted
// TC :
// SC :
// ######################################
int height(Node *node)
{
    // code here

    if (node == NULL)
        return 0;

    int cnt = 0;
    queue<Node *> q;
    q.push(node);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cnt++;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
    return cnt;
}

// ######################################
// Using Recursion
// Source : Babbar Approach
// TC : O(N) N = number of nodes in the tree
// SC : O(h) h = height of the binary tree = number of recursive calls
// SC worst case = O(N) in a skewed binary tree
// ######################################

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root)
{
    // base case
    if (root == NULL)
        return 0;

    int right_cnt = maxDepth(root->right);
    int left_cnt = maxDepth(root->left);

    int ans = max(left_cnt, right_cnt) + 1;
    return ans;
}

int main()
{

    return 0;
}