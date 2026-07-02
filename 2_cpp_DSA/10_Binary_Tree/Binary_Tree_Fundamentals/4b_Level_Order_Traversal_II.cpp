// Name : Yash Deshpande
// Date : 02-07-2026
// LeetCode : Binary Tree Level Order Traversal II
// Link : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
//
// NOTE : This is the LeetCode style function signature -> returns vector<vector<int>>
//        (each level grouped separately, ordered bottom-up).
//        A different function signature (returns a flat vector<int>) is covered in
//        4_Reverse_Level_Order_Traversal.cpp in the same directory.

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        // Base Case
        if(!root) {
            return ans;
        }

        vector<int> level;

        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            // Null check
            if(temp == nullptr) {
                ans.push_back(level);
                level.clear();

                if(!q.empty()) {
                    q.push(nullptr);
                }
            }
            else {
                level.push_back(temp->val);
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main()
{

    return 0;
}
