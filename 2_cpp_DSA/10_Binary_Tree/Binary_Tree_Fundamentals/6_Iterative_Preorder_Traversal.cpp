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

// Iterative Preorder Traversal
// TC : O(N)
// SC : O(N)
vector <int> iterativePreorderTraversal (Node *root)
{
    vector <int> preorder;

    // Check if root is not NULL
    if(!root)
        return preorder;

    stack <Node *>st;
    st.push(root);

    while(!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        preorder.push_back(temp->data);

        if(temp->right)
        {
            st.push(temp->right);
        }

        if(temp->left)
        {
            st.push(temp->left);
        }
    }
    return preorder;
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

    // Iterative Preorder Traversal
    cout << "Preorder traversal is ";
    iterativePreorderTraversal(root);                     // 1 3 7 11 5 17
    return 0;
}