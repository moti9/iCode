#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    string serialize(TreeNode *node, unordered_map<string, int> &freq, vector<TreeNode *> &res)
    {
        if (node == nullptr)
        {
            return "#";
        }

        string left = serialize(node->left, freq, res);
        string right = serialize(node->right, freq, res);
        string s = to_string(node->val) + "," + left + "," + right;

        if (++freq[s] == 2)
        {
            res.push_back(node);
        }

        return s;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> freq;
        vector<TreeNode *> res;
        serialize(root, freq, res);
        return res;
    }
};


void printTree(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->val;
    if (node->left != nullptr || node->right != nullptr)
    {
        cout << " (";
        printTree(node->left);
        cout << ", ";
        printTree(node->right);
        cout << ")";
    }
}
void printDuplicateSubtrees(vector<TreeNode *> subtrees)
{
    for (TreeNode *node : subtrees)
    {
        cout << "[";
        printTree(node);
        cout << "] ";
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    Solution sol;
    vector<TreeNode *> ans = sol.findDuplicateSubtrees(root);
    printDuplicateSubtrees(ans);

    return 0;
}