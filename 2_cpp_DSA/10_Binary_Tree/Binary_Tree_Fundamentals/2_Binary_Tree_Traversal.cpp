// Name : Yash Deshpande
// Date : 15-04-2024
// Tutuor : Love Babbar

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

// Create a binary tree
// Recursive Function
Node *buildTree(Node *root)
{
    cout << "Enter data for node : ";
    int data;
    cin >> data;
    root = new Node(data);

    // Enter -1 if no further child node is to be created
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting at the Left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting at the Right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Type-1 : without separator
// void levelOrderTraversal(Node* root)
// {
//     queue <Node*>q;

//      // Check if root is not NULL
//      if(!root)
//          return;

//     // push root node into queue
//     q.push(root);

//     //
//     while(!q.empty())
//     {
//         Node* temp = q.front();
//         cout<<temp->data<<" ";
//         q.pop();

//         if(temp->left)
//             q.push(temp->left);

//         if(temp->right)
//             q.push(temp->right);
//     }
// }

// Type - 2 : with separator
void levelOrderTraversal(Node *root)
{
    // Check if root is not NULL
    if(!root)
        return;

    queue<Node *> q;

    // push root node into queue
    q.push(root);
    // NULL used as a separator
    q.push(NULL);

    //
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

// L -> Go to Left child
// R -> Go to Right child
// N -> Print Data of current Node

void inorder(Node *root)
{
    // LNR

    // Base Case
    if (root == NULL)
        return;

    inorder(root->left);       // L
    cout << root->data << " "; // N
    inorder(root->right);      // R
}

void preorder(Node *root)
{
    // NLR

    // Base Case
    if (root == NULL)
        return;

    cout << root->data << " "; // N
    preorder(root->left);      // L
    preorder(root->right);     // R
}

void postorder(Node *root)
{
    // LRN

    // Base Case
    if (root == NULL)
        return;

    postorder(root->left);     // L
    postorder(root->right);    // R
    cout << root->data << " "; // N
}

int main()
{
    Node *root = NULL;

    // creating a tree
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order Traversal
    // Try both types
    cout << "Printing level order traversal" << endl;
    levelOrderTraversal(root);

    // Inorder Traversal
    cout << "Inorder traversal is ";
    inorder(root);                      // 7 3 11 1 17 5

    // Preorder Traversal
    cout << "Preorder traversal is ";
    preorder(root);                     // 1 3 7 11 5 17

    // Postorder Traversal
    cout << "Postorder traversal is ";
    postorder(root);                    // 7 11 3 17 5 1

    return 0;
}
