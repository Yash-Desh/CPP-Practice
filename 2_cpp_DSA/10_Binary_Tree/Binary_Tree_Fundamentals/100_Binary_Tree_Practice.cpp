#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr){}
};

Node* CBT_iterative(vector<int> &nums) {
    // Base Case.
    if(nums.size() == 0) {
        return nullptr;
    }

    // Level Order Traversal
    Node *root = new Node(nums[0]);
    int index = 1;

    queue<Node*> q;
    q.push(root);

    while(index < nums.size()) {
        auto node = q.front();
        q.pop();

        if(index < nums.size()) {
            node->left = new Node(nums[index++]);
            q.push(node->left);
        }

        if(index < nums.size()) {
            node->right = new Node(nums[index++]);
            q.push(node->right);
        }
    }
    return root;
}

Node* CBT_recursive(vector<int> &nums, int index) {
    // Base Case.
    if(index >= nums.size()) {
        return nullptr;
    }

    Node* root = new Node(nums[index]);
    root->left = CBT_recursive(nums, 2*index+1);
    root->right = CBT_recursive(nums, 2*index+2);

    return root;
}

void printTree(Node* root) {
    if (!root) {
        return;
    }
      printTree(root->left);
    cout << root->data << " ";
  
    printTree(root->right);
}


int main()
{
    // Do Not Change This.
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    Node* root1 = CBT_iterative(nums);
    printTree(root1);                    // 6 4 6 2 5 1 6 3 6

    cout<<endl;

    Node* root2 = CBT_recursive(nums, 0);
    printTree(root2);                    // 6 4 6 2 5 1 6 3 6
    return 0;
}
