// Author : Yash Deshpande
// Date   : 30-08-2025
// Tutor  : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};
 

class Solution{
	public:

    // TC : O(H)
    // SC : O(1)
		TreeNode* inOrderPredecessor(TreeNode* root, TreeNode* p){
			TreeNode* predecessor = nullptr;
            while(root != nullptr) {
                if(p->data > root->data) {
                    predecessor = root;
                    root = root->right;
                }
                else{
                    root = root->left;
                }
            }
            return predecessor;
		}
};

int main() {
    return 0;
}