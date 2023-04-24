#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool invert(TreeNode *&t1, TreeNode *&t2)
{
    if (t1 == NULL || t2 == NULL)
    {
        return false;
    }
    swap(t1->data, t2->data);
    return invert(t1->left, t2->right) && invert(t1->right, t2->left);
}

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return root;
    }
    invert(root->left, root->right);

    return root;
}

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return root;
    }
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);
    return root;
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

    return 0;
}