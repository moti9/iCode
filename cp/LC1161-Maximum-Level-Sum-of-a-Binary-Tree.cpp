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
public:
    int maxLevelSum(TreeNode *root)
    {
        int level = 0;
        if (root == nullptr)
        {
            return 0;
        }
        int sum = -1e9;
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            int sz = q.size();
            int temp = 0;
            level += 1;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                temp += node->val;
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            if (sum < temp)
            {
                sum = temp;
                ans = level;
            }
        }
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

    return 0;
}
