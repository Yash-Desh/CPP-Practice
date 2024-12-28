// Name : Yash Deshpande
// Date : 18-04-2024
// Tutuor : Love Babbar, code library YT

#include <bits/stdc++.h>
using namespace std;


// ########################################
// Approach : 
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

int main()
{

    return 0;
}