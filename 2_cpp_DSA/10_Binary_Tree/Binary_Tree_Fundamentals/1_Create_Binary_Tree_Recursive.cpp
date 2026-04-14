// Name : Yash Deshpande
// Date : 15-04-2024
// Tutuor : Love Babbar
// Last Read : 28-12-2024

#include <iostream>
#include <queue>
using namespace std;

/* Create a Binary Tree
      1
    /   \
  3       5 
 / \     /
7   11  17 

*/

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // parameterized constructor
    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

// Create a binary tree
// Recursive Function
// There is no real need for providing the root as a parameter.
// We can simply create new Node object within the function & 
// then return that Node. 
// Node* buildTree() {}
Node *buildTree(Node *root)
{
    // create node
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

// Level Order Traversal
void levelOrderTraversal(Node *root)
{
    // Base Case
    if(root == nullptr) { return; }

    queue<Node *> q;

    // push root node into queue
    q.push(root);

    //
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}

int main()
{
    Node *root = NULL;

    // creating a tree
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order Traversal
    cout << "Printing level order traversal" << endl;
    levelOrderTraversal(root);                              // 1 3 5 7 11 17

    return 0;
}
