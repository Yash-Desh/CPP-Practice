#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void buildTreeLevelOrder(Node *&root)
{
    queue<Node *> q;

    // Create the root node.
    int data;
    cout << "data for root node ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "data for left root node ";
        cin >> data;
        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "data for right root node ";
        cin >> data;
        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;

    buildTreeLevelOrder(root);
    return 0;
}
