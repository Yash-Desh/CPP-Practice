// Name : Yash Deshpande
// Date : 16-04-2024
// Tutuor : Love Babbar

// WARNING : For some reason unknown, this code did not execute properly the last time I tested it
// It is an exact replica from the code taught by Love Babbar in Video-62, so thats not the issue

#include <iostream>
#include <queue>
using namespace std;

/* Create a Binary Tree
      2
    /   \
  3       5
 / \     /
7   11  17

*/

class Node{
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

// Binary Tree creation 
// Method-2 : From Level Order Traversal
void buildFromLevelOrder (Node* &root)
{
    // create queue
    queue <Node*> q;

    // create root node
    cout<<"Enter data for root :";
    int rootData;
    cin>>rootData;
    root = new Node(rootData);

    // push root node into queue
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // for left child node
        cout<<"Enter data for Left Node of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        // if data is not -1, push node to queue
        if(leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        // for right child node
        cout<<"Enter data for Right Node of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        // if data is not -1, push node to queue
        if(rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}


// Level Order Traversal
void levelOrderTraversal(Node* root)
{
    queue <Node*>q; 

    // push root node into queue
    q.push(root);
    // NULL used as a separator
    q.push(NULL);

    //
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    Node* root = NULL;

    buildFromLevelOrder(root);

    cout<<"Printing level order traversal"<<endl;
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    return 0;
}