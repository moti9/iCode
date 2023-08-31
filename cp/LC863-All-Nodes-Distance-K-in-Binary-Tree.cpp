#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    void createGraph(TreeNode *node, TreeNode *parent, unordered_map<int, vector<int>> &graph)
    {
        if (node != NULL && parent != NULL)
        {
            graph[parent->val].push_back(node->val);
            graph[node->val].push_back(parent->val);
        }
        if (node != NULL && node->left != NULL)
        {
            createGraph(node->left, node, graph);
        }
        if (node != NULL && node->right != NULL)
        {
            createGraph(node->right, node, graph);
        }
    }

    void findNodes(int node, int k, unordered_map<int, vector<int>> &graph, unordered_set<int> &vis, vector<int> &ans)
    {
        if (k == 0)
        {
            ans.push_back(node);
            return;
        }
        vis.insert(node);
        for (auto &adjNode : graph[node])
        {
            if (!vis.count(adjNode))
            {
                findNodes(adjNode, k - 1, graph, vis, ans);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<int, vector<int>> graph;
        createGraph(root, NULL, graph);
        vector<int> ans;
        unordered_set<int> vis;
        vis.insert(target->val);

        findNodes(target->val, k, graph, vis, ans);
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

    int dist = 2;
    Solution sol;
    vector<int> ans = sol.distanceK(root, root, dist);

    for (auto &a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}