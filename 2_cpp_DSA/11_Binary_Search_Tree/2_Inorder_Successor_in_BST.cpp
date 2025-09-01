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
		TreeNode* inOrderSuccessor(TreeNode* root, TreeNode* p){
			TreeNode* successor = nullptr;
            while(root != nullptr) {
                if(p->data > root->data) {
                    root = root->right;
                }
                else{
                    successor = root;
                    root = root->left;
                }
            }
            return successor;
		}
};

int main() {
    return 0;
}