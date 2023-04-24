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
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int sz = q.size();
            int curr = q.front().second;
            int leftMost, rightMost;
            for (int i = 0; i < sz; i++)
            {
                root = q.front().first;
                int currCnt = q.front().second - curr;
                if (i == 0)
                    leftMost = currCnt;
                if (i == sz - 1)
                    rightMost = currCnt;
                q.pop();
                if (root->left)
                {
                    q.push({root->left, currCnt * 2 + 1});
                }
                if (root->right)
                {
                    q.push({root->right, currCnt * 2 + 2});
                }
            }
            ans = max(ans, rightMost - leftMost + 1);
        }
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    // root->left->right->left = new TreeNode(8);
    // root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    // root->right->right->left = new TreeNode(9);
    // root->right->right->right = new TreeNode(10);
    Solution sol;
    cout << sol.widthOfBinaryTree(root) << endl;

    return 0;
}