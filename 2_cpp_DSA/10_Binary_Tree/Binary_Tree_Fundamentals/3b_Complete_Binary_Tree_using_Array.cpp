// Name : Yash Deshpande
// Date : 22-09-2025
// Tutuor : https://www.geeksforgeeks.org/dsa/construct-complete-binary-tree-given-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Create a Binary Tree
      2
    /   \
  3       5
 / \     /
7   11  17

*/

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// ###############################
// Iterative Approach
// ###############################
Node* build_CBT_iterative(vector<int> nums) {
    // Base Case.
    if(nums.size() == 0) {
        return nullptr;
    }

    queue<Node *> q;
    
    // Create the root node.
    Node* root = new Node(nums[0]);
    q.push(root);
    
    // Traverse the array.
    int index = 1;
    while(index < nums.size()) {
        Node* front = q.front();
        q.pop();

        if(index < nums.size()) {
            front->left = new Node(nums[index++]);
            q.push(front->left);
        }

        if(index < nums.size()) {
            front->right = new Node(nums[index++]);
            q.push(front->right);
        }
    }
    return root;
}


// ###############################
// Recursive Approach
// ###############################
Node* build_CBT_recursive(vector<int> nums, int index) {
    // Base Case
    if(index >= nums.size()) {
        return nullptr;
    }

    Node *root = new Node(nums[index]);
    root->left = build_CBT_recursive(nums, 2*index+1);
    root->right = build_CBT_recursive(nums, 2*index+2);

    return root;
}

// Utility Functions
void print_level_order_traversal(Node *root) {
    queue<Node *> q;
    if(root == nullptr) {
        return;
    }

    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        if(front == nullptr) {
            if(!q.empty()) {
                q.push(nullptr);
            }
            cout<<endl;
        }
        else {
            cout<<front->data<<" ";

            if(front->left) {
                q.push(front->left);
            }

            if(front->right) {
                q.push(front->right);
            }
        }
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 11, 17};
    Node *root = build_CBT_recursive(arr, 0);
    print_level_order_traversal(root);

    return 0;
}

