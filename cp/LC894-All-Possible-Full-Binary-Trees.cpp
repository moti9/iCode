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
    vector<TreeNode *> possibleBFT(int n, unordered_map<int, vector<TreeNode *>> &nodeList)
    {
        if (n % 2 == 0)
        {
            return {};
        }
        if (n == 1)
        {
            return {new TreeNode(0)};
        }
        if (nodeList.find(n) != nodeList.end())
        {
            return nodeList[n];
        }

        vector<TreeNode *> nodes;
        for (int x = 1; x < n; x += 2)
        {
            int y = n - 1 - x;
            vector<TreeNode *> leftBFT = possibleBFT(x, nodeList);
            vector<TreeNode *> rightBFT = possibleBFT(y, nodeList);

            for (int left = 0; left < leftBFT.size(); left++)
            {
                for (int right = 0; right < rightBFT.size(); right++)
                {
                    TreeNode *node = new TreeNode(0);
                    node->left = leftBFT[left];
                    node->right = rightBFT[right];
                    nodes.push_back(node);
                }
            }
        }

        return nodeList[n] = nodes;
    }

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        unordered_map<int, vector<TreeNode *>> nodeList;
        return possibleBFT(n, nodeList);
    }
};

int main()
{
    return 0;
}