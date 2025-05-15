// Name : Yash Deshpande
// Date : 13-03-2025
// Tutuor : Love Babbar

#include <iostream>
using namespace std;

// ###################################### VARIANTS #############################################
// Diameter of a Binary Tree could be counted as
//  1. Number of Nodes
//  2. Number of Edges

// The answer & the method changes in either case
// Check twice what the question wants
// #########################################################################################

// ##########################################
// Nodes Method - 1
// Babbar Method - 1
// TC = O(N^2)  -> height is called inside of diameter
// SC = O(N)

// ##########################################

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int right_height = height(root->right);
    int left_height = height(root->left);
    int max_height = max(right_height, left_height) + 1;

    return max_height;
}

int diameter(Node *root)
{
    // Your code here
    if (root == NULL)
    {
        return 0;
    }

    int diameter_left_sub_tree = diameter(root->left);
    int diameter_right_sub_tree = diameter(root->right);

    int diameter_across_sub_tree = height(root->left) + height(root->right) + 1;

    return max(diameter_across_sub_tree, max(diameter_left_sub_tree, diameter_right_sub_tree)) - 1;
}

// ##########################################
// Nodes Method - 2
// Babbar Method - 2
// TC = O(N^2)  -> height is called inside of diameter
// SC : O(h) h = height of the binary tree = number of recursive calls
// SC worst case = O(N) in a skewed binary tree
// ##########################################

pair<int, int> diameter_fast(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> temp = make_pair(0, 0);
        return temp;
    }

    pair<int, int> left = diameter_fast(root->left);
    pair<int, int> right = diameter_fast(root->right);

    int left_diameter = left.first;
    int right_diameter = right.first;

    int cross_tree_diameter = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(cross_tree_diameter, max(left_diameter, right_diameter));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node *root)
{
    return diameter_fast(root).first - 1;
}

int main()
{

    return 0;
}