// Name : Yash Deshpande
// Date : 16-04-2024
// Tutuor : Love Babbar

#include <iostream>
#include <queue>
using namespace std;

// Following is the Binary Tree Node class structure:

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


// ########################################

// Outcome : Level Order Traversal, AC
// My Approach
// TC : O(N)
// SC : O()

// ########################################

#include <queue>
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    int ans = 0;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        if (temp->left == NULL && temp->right == NULL)
            ans++;
        q.pop();

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
    return ans;
}


// ########################################

// Outcome : In-order traversal, AC
// Babbar Approach
// TC : O(N)   N= number of nodes in the tree
// SC : O(1)

// ########################################
void inorder (BinaryTreeNode<int> *root, int & cnt)
{
    // Base Case
    if(root == NULL)
        return;

    inorder(root->left, cnt);

    if(root->left == NULL && root->right == NULL)
        cnt++;

    inorder(root->right, cnt);
}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int cnt =0;
    inorder(root, cnt);
    return cnt;
}


int main()
{

    return 0;
}