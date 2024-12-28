// Name : Yash Deshpande
// Date : 18-04-2024
// Tutuor : Love Babbar, Striver

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

// Iterative Inorder Traversal
// TC : O(N)
// SC : O(N)
vector <int> iterativeInorderTraversal (Node *root)
{
    vector <int> inorder;
    stack <Node *> st;

    // Check if root is not NULL
    if(!root)
        return inorder;

    Node *temp = root;

    while(true)
    {
        if(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if(st.empty())
            {
                break;
            }
            temp = st.top();
            st.pop();
            inorder.push_back(temp->data);
            cout<<temp->data<<" ";
            temp = temp->right; 
        }
    }
    return inorder;
}









// Helper Function
// Create a binary tree
// Recursive Function
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

int main()
{
    Node *root = NULL;

    // creating a tree
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // Iterative inorder Traversal
    cout << "Printing level order traversal" << endl;
    iterativeInorderTraversal(root);                    // 7 3 11 1 17 5

    return 0;
}