#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

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
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<pair<TreeNode *, bool>> q;
        q.push({root, false});

        int sum = 0;

        while (!q.empty())
        {
            pair<TreeNode *, bool> current = q.front();
            q.pop();
            TreeNode *node = current.first;
            bool isLeft = current.second;

            TreeNode *left = node->left;
            TreeNode *right = node->right;

            if (left == nullptr && right == nullptr)
            {
                (isLeft) ? sum += node->val : sum += 0;
                continue;
            }

            if (left)
                q.push({left, true});
            if (right)
                q.push({right, false});
        }

        return sum;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}