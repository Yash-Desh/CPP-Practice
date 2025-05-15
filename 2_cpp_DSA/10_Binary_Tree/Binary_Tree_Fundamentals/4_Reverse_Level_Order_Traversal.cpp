// Name : Yash Deshpande
// Date : 18-04-2024
// Tutuor : Love Babbar, code library YT

#include <bits/stdc++.h>
using namespace std;


// ########################################
// Approach-1 : Brute Force
// Code Library Approach
// TC : O(N)  -> N is the number of nodes
// SC : O(N)
// ########################################
struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    queue<Node *> q;

    // check if root is not NULL
    if (!root)
    {
        return ans;
    }

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        if (temp->right)
            q.push(temp->right);

        if (temp->left)
            q.push(temp->left);
    }


    // Reverse the vector
    reverse(ans.begin(), ans.end());
    return ans;
}

// ########################################
// Approach-2 : Optimal -> using stacks
// Source : GFG
// TC : O(N)  -> N is the number of nodes
// SC : O(N)
// ########################################

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node (int data)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void reverse_level_order_traversal(Node *root)
{
    // declarations
    queue <Node *> q;
    stack <Node *> st;
    q.push(root);

    // level-order while loop
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        st.push(temp);

        // Enqueue the right 
        if(temp->right)
            q.push(temp->right);

        // Enqueue the left
        if(temp->left)
            q.push(temp->left);
    }

    // print the stack
    while(!st.empty())
    {
        Node *temp = st.top();
        cout<<temp->data<<" ";
        st.pop();
    }
}


int main()
{

    return 0;
}