// Date: 06-05-2026
// Author: Yash Deshpande

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree() {
    int rootData;
    cout << "Enter data for root node";
    cin >> rootData;

    if(rootData == -1) {
        return nullptr;
    }

    Node* temp = new Node(rootData);
    int leftData;
    cout << "Enter data for the left of " << rootData << endl;
    temp->left = buildTree();

    int rightData;
    cout << "Enter data for the right of " << rootData << endl;
    temp->right = buildTree();
    return temp;
}

Node* buildTreeFromLevelOrder() {
    int rootData;
    cout << "Enter data for the root: ";
    cin >> rootData;

    if(rootData == -1) {
        return nullptr;
    }

    Node* root = new Node(rootData);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        auto front = q.front();
        q.pop();

        int leftData; 
        cout << "Enter data for the left of " << front->data;
        cin >> leftData;
        if(leftData != -1) {
            front->left = new Node(leftData);
            q.push(front->left);
        }

        int rightData; 
        cout << "Enter data for the right of " << front->data;
        cin >> rightData;
        if(rightData != -1) {
            front->right = new Node(rightData);
            q.push(front->right);
        }
    }
    
    return root;
}

Node* buildCBT_iterative(vector<int> &nums) {
    if(nums.size() == 0) { return nullptr; }

    queue<Node*> q;
    int index = 0;
    Node* root = new Node(nums[index++]);
    q.push(root);

    while(index < nums.size()) {
        auto front = q.front();
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

Node* buildCBT_recursive(vector<int> &nums, int pos) {
    if(pos >= nums.size()) {
        return nullptr;
    }

    Node* root = new Node(nums[pos]);
    root->left = buildCBT_recursive(nums, 2 * pos + 1);
    root->right = buildCBT_recursive(nums, 2 * pos + 2);
    return root;
}


void levelOrderTraversal(Node* root) {
    // Base Case
    if(root == nullptr) {
        return;
    }
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        cout << front->data << " ";

        if(front->left) {
            q.push(front->left);
        }
        if(front->right) {
            q.push(front->right);
        }
    }
}


void levelOrderTraversalTree(Node* root) {
    if(root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        auto front = q.front();
        q.pop();

        if(front == nullptr) {
            if(!q.empty()) {
                q.push(nullptr);
            }
            cout << endl;
        }
        else {
            cout << front->data << " ";
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
    }

}



int main()
{
    // -------------------------- Test buildTree() -------------------------- // 
    // Node* root = nullptr;
    // root = buildTree();             // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout << "Printing level order traversal" << endl;
    // levelOrderTraversal(root);
    // cout << endl;                   // 1 3 5 7 11 17

    // cout << "Printing level order traversal in tree form" << endl;
    // levelOrderTraversalTree(root);
    // cout << endl;

    // cout << endl << "Printing in order traversal " << endl;
    // inOrder(root);


    // -------------------------- Test buildTreeFromLevelOrder() -------------------------- //
    // Node* root = nullptr;
    // root = buildTreeFromLevelOrder();               // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // cout << "Printing level order traversal" << endl;
    // levelOrderTraversal(root);
    // cout << endl;                                   // 1 3 5 7 11 17

    // cout << "Printing level order traversal in tree form" << endl;
    // levelOrderTraversalTree(root);
    // cout << endl;

    // -------------------------- Test buldCBT_*() -------------------------- //
    vector<int> nums = {1, 3, 5, 7, 11, 17};
    Node* root1 = buildCBT_iterative(nums);
    levelOrderTraversalTree(root1);                 // 1 
                                                    // 3 5
                                                    // 7 11 17

    cout<<endl;

    Node* root2 = buildCBT_recursive(nums, 0);
    levelOrderTraversalTree(root2);
    
    return 0;
}
