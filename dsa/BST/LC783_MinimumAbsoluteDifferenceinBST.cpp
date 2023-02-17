#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    void getNodes(TreeNode *root, vector<int> &num)
    {
        if (root == NULL)
        {
            return;
        }
        getNodes(root->left, num);
        num.push_back(root->val);
        getNodes(root->right, num);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> num;
        getNodes(root, num);
        int ans = 1e7;
        for (int i = 1; i < num.size(); i++)
        {
            ans = min(ans, num[i] - num[i - 1]);
        }
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    cout << sol.getMinimumDifference(root) << endl;

    return 0;
}