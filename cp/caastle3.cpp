#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct TreeNode
{
    int data;
    TreeNode *left, *right;
};

TreeNode *newNode(int data)
{
    TreeNode *node = new TreeNode;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

vector<vector<int>> diagonalPrint(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;

    queue<TreeNode *> nodeQue;
    nodeQue.push(root);

    while (!nodeQue.empty())
    {
        int size = nodeQue.size();
        vector<int> answer;

        while (size--)
        {
            TreeNode *temp = nodeQue.front();
            nodeQue.pop();

            while (temp)
            {
                answer.push_back(temp->data);

                if (temp->left)
                    nodeQue.push(temp->left);

                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
    return result;
}

int main()
{
    TreeNode *root = newNode(1);
    root->left = newNode(4);
    root->right = newNode(2);
    root->left->left = newNode(8);
    root->left->right = newNode(5);
    root->right->right = newNode(3);
    root->right->right->left = newNode(6);
    root->left->right->left = newNode(9);
    root->left->right->right = newNode(7);

    vector<vector<int>> result = diagonalPrint(root);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
