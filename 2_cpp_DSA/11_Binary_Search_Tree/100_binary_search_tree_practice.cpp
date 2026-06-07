// Author: Yash Deshpande
// Date  : 29-03-2026
// Change the date whenever you overwrite the file. 

#include <iostream>
#include <queue>
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

Node* insertIntoBST(Node* root, int data) {
    if(root == nullptr) {
        root = new Node(data);
    } 
    else {
        if(root->data >= data) {
            root->left = insertIntoBST(root->left, data);
        }
        else {
            root->right = insertIntoBST(root->right, data);
        }
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cout << "Enter data for the root" << endl;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data for the root" << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
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

int main() {
    Node *root = nullptr;

    cout<<"Enter Data for BST : ";   // 10 8 21 7 27  5 4 3 -1
    takeInput(root);                 // 50 20 70 10 30 90 110 -1 
    
    cout<<"Displaying the BST in level order : " << endl;
    levelOrderTraversal(root);

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

    // cout<<endl<<"Displaying the BST in inorder : ";
    // displayBST_inOrder(root);       // 3 4 5 7 8 10 21 27
    // // Notice the sorted order

    // cout<<endl<<"Max value in the BST : "<<maxValue(root)->data<<endl;
    // cout<<"Min value in the BST : "<<minValue(root)->data<<endl;

    // root = deleteFromBST(root, 90);
    // displayBST_levelOrder(root);

    return 0;
}