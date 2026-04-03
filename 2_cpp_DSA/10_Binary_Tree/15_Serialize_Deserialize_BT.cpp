#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        // Level Order Traversal
        string ans = "";

        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto frontNode = q.front();
            q.pop();

            if (frontNode == nullptr) {
                ans += "#,";
            }
            else {
                ans += to_string(frontNode->val) + ",";
                q.push(frontNode->left);
                q.push(frontNode->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0){
            return nullptr;
        }

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()){
            auto frontNode = q.front();
            q.pop();

            getline(ss, str, ',');
            if (str == "#"){
                frontNode->left = nullptr;
            }
            else{
                frontNode->left = new TreeNode(stoi(str));
                q.push(frontNode->left);
            }

            getline(ss, str, ',');
            if (str == "#"){
                frontNode->right = nullptr;
            }
            else{
                frontNode->right = new TreeNode(stoi(str));
                q.push(frontNode->right);
            }
        }
        return root;
    }
};

int main()
{
    return 0;
}