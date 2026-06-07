// Date: 28-03-2026

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Create Binary Tree
// Traverse Binary Tree

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// -------------------------- Construct Binary Tree -------------------------- //

Node* buildTree() {
    cout << "Enter data for the root" << endl;
    int data;
    cin >> data;

    if(data == -1) {
        return nullptr;
    }
    Node* temp = new Node(data);

    cout << "Enter data for the left node of " << temp->data <<endl;
    temp->left = buildTree();

    cout << "Enter data for the right node of " << temp->data << endl;
    temp->right = buildTree();

    return temp;
}

Node* buildTreeFromLevelOrder() {
    cout << "Enter data for the root node " << endl;
    int rootData;
    cin >> rootData;

    if(rootData == -1) { return nullptr; }
    Node* root = new Node(rootData);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for the left of " << temp->data << endl;
        cin >> leftData;
        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for the right of " << temp->data << endl;
        cin >> rightData;
        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

Node* buildCBT_iterative(vector<int> nums) {
    // Base Case
    if(nums.size() == 0) { return nullptr; }

    Node* root = new Node(nums[0]);
    queue<Node*> q;
    q.push(root);

    int index = 1;
    while(index < nums.size()) {
        Node* temp = q.front();
        q.pop();

        if(index < nums.size()) {
            temp->left = new Node(nums[index++]);
            q.push(temp->left);
        }
        if(index < nums.size()) {
            temp->right = new Node(nums[index++]);
            q.push(temp->right);
        } 
    }
    return root;
}

Node* buildCBT_recursive(vector<int> nums, int index) {
    // Base Case
    if(index >= nums.size()) {
        return nullptr;
    }

    Node* temp = new Node(nums[index]);
    temp->left = buildCBT_recursive(nums, 2 * index + 1);
    temp->right = buildCBT_recursive(nums, 2 * index + 2);
    return temp;
}

class Solution {
    Node* solve(int &pIndex, int iLeft, int iRight, vector<int>& preorder, vector<int>& inorder) {
        // Base Case
        if(pIndex >= preorder.size() || iLeft < 0 || iRight >= inorder.size()) {
            return nullptr;
        }

        Node* root = new Node(preorder[pIndex]);

        // Locate preorder[pIndex]
        int pos = -1;
        for(int i=iLeft; i<= iRight; i++) {
            if(inorder[i] == preorder[pIndex]) {
                pos = i;
                break;
            }
        }
        if(pos == -1) { return nullptr; }
        pIndex++;
        root->left = solve(pIndex, iLeft, pos-1, preorder, inorder);
        root->right = solve(pIndex, pos+1, iRight, preorder, inorder);

        return root;
    }
public:
    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pIndex = 0;
        return solve(pIndex, 0, inorder.size()-1, preorder, inorder);
    }
};


// -------------------------- Traversal -------------------------- //

void levelOrderTraversal(Node* root) {
    // Base Case
    if(root == nullptr) { return; }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
}

void levelOrderTraversalTree(Node* root) {
    // Base Case
    if(root == nullptr) { return; }

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == nullptr) {
            cout << endl;
            if(!q.empty()) {
                q.push(nullptr);
            }
        }
        else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node* root) {
    // Base Case
    if(root == nullptr) { return; }

    inOrderTraversal(root->left);
    cout << root->data;
    inOrderTraversal(root->right);
}

vector<int> inOrderTraversalMorris (Node* root) {
    vector<int> ans;

    while(root != nullptr) {
        if(root->left == nullptr) {
            ans.push_back(root->data);
            root = root->right;
        } 
        else {
            // Find the inorder Successor
            Node* temp = root->left;
            while(temp->right != nullptr && temp->right != root) {
                temp = temp->right;
            }
            if(temp->right != root) {
                temp->right = root;
                root = root->left;
            }
            else {
                temp->right = nullptr;
                ans.push_back(root->data);
                root = root->right;
            }
        }
    }
    return ans;
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
