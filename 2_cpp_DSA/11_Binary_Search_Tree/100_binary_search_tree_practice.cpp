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
    // Base Case
    if(root == nullptr) {
        Node* temp = new Node(data);
        return temp;
    }

    if(data < root->data) {
        root->left = insertIntoBST(root->left, data);
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
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
            continue;
        }
        cout << temp->data << " ";

        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
}

Node* inOrderSuccessor(Node* root, Node* p) {
    // Iterative
    Node* successor = nullptr;
    
    while(root != nullptr) {
        if(root->data > p->data) {
            successor = root;
            root = root->left;
        } 
        else {
            root = root->right;
        }
    }

    return successor;
}


// Node* deleteFromBST(Node* root, int val) {
//     // Base Case
//     if(root == nullptr) {
//         return nullptr;
//     }

//     if(root->data == val)
// }


int main() {
    Node* root = nullptr;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);

    return 0;
}