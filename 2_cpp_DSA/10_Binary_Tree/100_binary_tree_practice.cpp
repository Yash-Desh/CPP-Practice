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

Node* buildTree(Node *root) {
    
    // Construct current Node
    int val;
    cin>>val;

    if(val == -1) {
        return nullptr;
    }
    root = new Node(val);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void buildTree_levelOrder(Node* &root) {
    queue<Node*> q;
    
    int data;
    cin>>data;
    root = new Node(data);

    q.push(root);
    while(!q.empty()) {
        Node *front = q.front();
        q.pop();

        int left_data;
        cin>>left_data;
        if(left_data != -1) {
            front->left = new Node(left_data);
            q.push(front->left);
        }
        
        int right_data;
        cin>>right_data;
        if(right_data != -1) {
            front->right = new Node(right_data);
            q.push(front->right);
        }
    }

}

void morris_traversal(Node *root) {
    Node *curr = root;
    while(curr != nullptr) {
        if(curr->left == nullptr) {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else {
            // find the rightmost element in the left subtree
            Node *temp = curr->left;
            while(temp->right != nullptr && temp->right != curr) {
                temp = temp->right;
            }

            if(temp->right == nullptr) {
                temp->right = curr;
                curr = curr->left;
            }
            else {
                temp->left = nullptr;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

void level_order_traversal(Node *root) {
    queue<Node *> q;
    if(root == nullptr) {
        return;
    }

    q.push(root);
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        cout<<front->data<<" ";

        if(front->left) {
            q.push(front->left);
        }

        if(front->right) {
            q.push(front->right);
        }
    }
}

int main() {

    Node *root = NULL;

    // creating a tree
    // root = buildTree(root);          // 2 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildTree_levelOrder(root);         // 2 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    
    // morris_traversal(root);

    level_order_traversal(root);
    return 0;
}