// Author : Yash Deshpande
// Date : 12-03-2025

#include <iostream>
#include <queue>
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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *build_tree(Node *root)
{
    cout << "Enter Data" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    // base case
    if (data == -1)
        return NULL;

    // Left Node
    root->left = build_tree(root->left);

    // Right Node
    root->right = build_tree(root->right);

    return root;
}

void level_order_traversal(Node *root)
{
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left)
            q.push(temp->left);

        if (root->right)
            q.push(temp->right);
    }
}

void level_order_creation(Node * &root)
{
    // input data & create a node
    queue <Node *>q;
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    root = new Node (data);

    q.push(root);

    // while queue
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // if left
        cout<<"Enter left data"<<endl;
        cin>>data;
        if(data != -1)
        {
            Node *left_node = new Node (data);
            temp->left = left_node;
            q.push(left_node);  
        }


        // if right
        cout<<"Enter right data"<<endl;
        cin>>data;
        if(data != -1)
        {
            Node *right_node = new Node (data);
            temp->right = right_node;
            q.push(right_node);  
        }
    }
    
}

int main()
{
    Node *root = NULL;

    // creating a tree
    level_order_creation(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order Traversal
    cout << "Printing level order traversal" << endl;
    level_order_traversal(root);
    return 0;
}