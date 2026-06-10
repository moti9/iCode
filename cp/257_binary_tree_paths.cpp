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
    void solve(TreeNode *node, string ans, vector<string> &answer)
    {
        string latest_val = ans;
        if (latest_val == "")
        {
            latest_val += to_string(node->val);
        }
        else
        {
            latest_val += ("->" + to_string(node->val));
        }

        TreeNode *left = node->left;
        TreeNode *right = node->right;
        if (left == nullptr && right == nullptr)
        {
            if (latest_val != "")
            {
                answer.push_back(latest_val);
            }
            return;
        }

        if (left)
            solve(left, latest_val, answer);
        if (right)
            solve(right, latest_val, answer);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> answer;
        solve(root, "", answer);
        return answer;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(5);

    Solution sol;
    vector<string> answer = sol.binaryTreePaths(root);

    for (auto str : answer)
    {
        cout << str << " ";
    }

    return 0;
}