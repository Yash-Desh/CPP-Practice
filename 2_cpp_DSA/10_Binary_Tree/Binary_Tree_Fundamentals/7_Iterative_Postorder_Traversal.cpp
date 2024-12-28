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

// #######################################
// Approach : using 2-stacks
// Striver Approach
// TC : O(N)
// SC : O(N)
// #######################################
vector <int> iterativePostorder2Stack(Node *root)
{
    stack <Node *> s1, s2;
    vector <int> postorder;

    // Check if root is not NULL
    if(!root)
        return postorder;

    s1.push(root);
    while(!s1.empty())
    {
        Node *temp = s1.top();
        s2.push(temp);
        s1.pop();

        if(temp->left)
            s1.push(temp->left);

        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty())
    {
        Node *temp = s2.top();
        cout<<temp->data<<" ";
        postorder.push_back(temp->data);
        s2.pop();
    }
    return postorder;
}


// #######################################
// Approach : using 1-stacks
// Striver Approach
// TC : O(2N)
// SC : O(N)
// #######################################

vector <int> iterativePostorder1Stack(Node *root)
{
    stack <Node *> st;
    vector <int> postorder;

    Node *curr = root;
    while(!st.empty() || curr != NULL)
    {
        if(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        else
        {
            Node *temp = st.top()->right;
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                cout<<temp->data<<" ";
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                    cout<<temp->data<<" ";
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postorder;
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
    cout << "Postorder traversal is ";
    iterativePostorder2Stack(root);                     // 7 11 3 17 5 1


    cout << "Postorder traversal is ";
    iterativePostorder1Stack(root);

    return 0;
}