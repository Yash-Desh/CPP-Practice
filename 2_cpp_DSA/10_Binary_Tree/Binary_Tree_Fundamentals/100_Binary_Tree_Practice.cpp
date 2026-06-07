#include <iostream>
#include <queue>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

void levelOrderTraversal(Node* root);
void levelOrderTraversalTree(Node* root);
void inOrderTraversal(Node* root);

Node* buildTree() {
    int data;
    cout << "Enter data for the root: ";
    cin >> data;
    if(data == -1) {
        return nullptr;
    } 

    Node* root = new Node(data);
    cout << "Enter data for the left of " << data << endl;
    root->left = buildTree();
    cout << "Enter data for the right of " << data << endl;
    root->right = buildTree();

    return root;
}

int main() {

    // -------------------------- Test buildTree() -------------------------- // 
    Node* root = nullptr;
    root = buildTree();             // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Printing level order traversal" << endl;
    levelOrderTraversal(root);
    cout << endl;                   // 1 3 5 7 11 17

    cout << "Printing level order traversal in tree form" << endl;
    levelOrderTraversalTree(root);
    cout << endl;

    cout << endl << "Printing in order traversal " << endl;
    inOrderTraversal(root);

    return 0;
}

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