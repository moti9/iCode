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

    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution
{
    void solve(TreeNode *root, int dir, int cnt, int &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        if (dir == 0)
        {
            if (root->left != nullptr)
                solve(root->left, 0, 1, ans);
            if (root->right != nullptr)
                solve(root->right, 1, cnt + 1, ans);
        }
        else
        {
            if (root->left != nullptr)
                solve(root->left, 0, cnt + 1, ans);
            if (root->right != nullptr)
                solve(root->right, 1, 1, ans);
        }

        ans = max(ans, cnt);
        return;
    }

public:
    int longestZigZag(TreeNode *root)
    {
        int ans = 0;
        solve(root, -1, 0, ans);
        return ans;
    }
};

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
    cout << sol.longestZigZag(root) << endl;

    return 0;
}