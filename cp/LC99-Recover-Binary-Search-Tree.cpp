#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

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
    void dfs(TreeNode *root, vector<TreeNode *> &ino)
    {
        if (root == nullptr)
            return;
        dfs(root->left, ino);
        ino.push_back(root);
        dfs(root->right, ino);
    }

public:
    void recoverTree(TreeNode *root)
    {
        vector<TreeNode *> inorder;
        inorder.push_back(new TreeNode(INT_MIN));
        dfs(root, inorder);
        inorder.push_back(new TreeNode(INT_MAX));

        TreeNode *x = nullptr, *y = nullptr;
        for (int i = 1; i < inorder.size() - 1; i++)
        {
            if (inorder[i]->val > inorder[i + 1]->val)
            {
                if (!x)
                {
                    x = inorder[i];
                    y = inorder[i + 1];
                }
                else
                {
                    y = inorder[i + 1];
                }
            }
        }
        swap(x->val, y->val);
    }
};

void printTreeInorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    printTreeInorder(root->left);
    cout << root->val << " ";
    printTreeInorder(root->right);
}

/*
class Solution
{
public:
    void inorder(TreeNode *root, TreeNode *&prev, TreeNode *&x, TreeNode *&y)
    {
        if (!root)
            return;

        inorder(root->left, prev, x, y);
        if (prev && root->val < prev->val)
        {
            if (!x)
            {
                x = prev;
                y = root;
            }
            else
            {
                y = root;
                return;
            }
        }
        prev = root;
        inorder(root->right, prev, x, y);
    }
    void recoverTree(TreeNode *root)
    {
        TreeNode *prev = nullptr, *x = nullptr, *y = nullptr;
        inorder(root, prev, x, y);
        swap(x->val, y->val);
    }
};
*/

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    printTreeInorder(root);
    cout << "\n";

    Solution sol;
    sol.recoverTree(root);

    printTreeInorder(root);
    cout << "\n";

    return 0;
}