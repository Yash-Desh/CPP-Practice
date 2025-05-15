// Name : Yash Deshpande
// Date : 13-03-2025
// Tutuor : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Babbar Approach-1
// Brute Force
// TC : O(N^2)

class Node {
    public:
      int data;
      Node* left;
      Node* right;
  
      // Constructor to initialize a new node
      Node(int val) {
          data = val;
          left = NULL;
          right = NULL;
      }
  };

int height(Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    int right_cnt = height(root->right);
    int left_cnt = height(root->left);

    int ans = max(left_cnt, right_cnt) + 1;
    return ans;
}


bool isBalanced(Node* root) {
    // Base Case
    if(root == NULL)
    {
        return true;
    }
    
    bool left_tree = isBalanced(root->left);
    bool right_tree = isBalanced(root->right);
    
    bool height_diff = abs(height(root->left)-height(root->right)) <= 1;
    
    if(left_tree && right_tree && height_diff)
        return true;
        
    else
        return false;
    
}


// Babbar Approach -2
// Optimal Approach

pair <bool, int> fast_balance(Node* root)
{
    // base case
    if(root == NULL)
    {
        pair <bool, int> temp = make_pair(true, 0);
        return temp;
    }
    
    pair <bool, int> left = fast_balance(root->left);
    pair <bool, int> right = fast_balance(root->right);
    
    bool left_subtree = left.first;
    bool right_subtree = right.first;
    bool height_cond = abs(left.second - right.second) <= 1;
    
    int final_height = max(left.second, right.second) +1;
    bool final_condition = left_subtree && right_subtree && height_cond;
    
    pair <bool, int> ans = make_pair(final_condition, final_height);
    
    return ans;
}

bool isBalanced(Node* root) {
    // Code here
    return fast_balance(root).first;
}

int main()
{
    
    return 0;
}