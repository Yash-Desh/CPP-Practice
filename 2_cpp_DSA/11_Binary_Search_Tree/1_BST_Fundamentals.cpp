// Author : Yash Deshpande
// Date   : 30-08-2025
// Tutor  : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Creation/Insertion in a BST
// Insertion TC : O(Log N)
// Intuition : Similar to Binary Search

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

Node* insertIntoBST(Node* &root, int val) {
    // Base Case
    if(root == nullptr) {
        root = new Node (val);
        return root;
    }

    if(val > root->data) {
        root->right = insertIntoBST(root->right, val);
    }
    else {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin>>data;
    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

Node* minValue(Node *root) {
    if(root == nullptr)
        return nullptr;

    Node *temp = root;
    while(temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node *root) {
    if(root == nullptr)
        return nullptr;

    Node *temp = root;
    while(temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    if(root == nullptr) {
        return root;
    }

    if(root->data == val) {
        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        if(root->left != NULL && root->right != NULL) {
            // find min value from the right subtree
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    if(root->data > val) {
        root->left = deleteFromBST(root->left, val);
    }
    else {
        root->right = deleteFromBST(root->right, val);
    }
    return root;
}

// ############################
// Utility Functions
// ############################
void displayBST_levelOrder(Node *root) {
    queue<Node *> q;
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
            continue;
        }

        cout<<front->data<<" ";
        if(front->left) {
            q.push(front->left);
        }
        if(front->right) {
            q.push(front->right);
        }
    }
}

void displayBST_inOrder(Node *root) {
    if(root == nullptr) {
        return;
    }

    displayBST_inOrder(root->left);
    cout<<root->data<<" ";
    displayBST_inOrder(root->right);
}


int main() {
    Node *root = nullptr;

    cout<<"Enter Data for BST : ";   // 10 8 21 7 27  5 4 3 -1
    takeInput(root);                 // 50 20 70 10 30 90 110 -1 
    
    cout<<"Displaying the BST in level order : ";
    displayBST_levelOrder(root);

    /*
    Prints like :
    10 
    8 21 
    7 27 
    5 
    4 
    3 

    Actual Structure : 

               10 
              /  \
            8     21 
           /       \
          7          27 
         /
        5
       / 
      4 
     /
    3
    */

    cout<<endl<<"Displaying the BST in inorder : ";
    displayBST_inOrder(root);       // 3 4 5 7 8 10 21 27
    // Notice the sorted order

    cout<<endl<<"Max value in the BST : "<<maxValue(root)->data<<endl;
    cout<<"Min value in the BST : "<<minValue(root)->data<<endl;

    root = deleteFromBST(root, 90);
    displayBST_levelOrder(root);

    return 0;
}