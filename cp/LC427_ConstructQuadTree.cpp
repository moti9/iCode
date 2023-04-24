#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return buildTree(grid, 0, 0, n - 1, n - 1);
    }

    Node *buildTree(vector<vector<int>> &grid, int startX, int startY, int endX, int endY)
    {
        if (startX == endX && startY == endY)
        {
            return new Node(grid[startX][startY] == 1, true);
        }

        int midX = startX + (endX - startX) / 2;
        int midY = startY + (endY - startY) / 2;

        Node *topLeft = buildTree(grid, startX, startY, midX, midY);
        Node *topRight = buildTree(grid, startX, midY + 1, midX, endY);
        Node *bottomLeft = buildTree(grid, midX + 1, startY, endX, midY);
        Node *bottomRight = buildTree(grid, midX + 1, midY + 1, endX, endY);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            bool val = topLeft->val;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            return new Node(val, true);
        }
        else
        {
            return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
};

void printQuadTree(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->isLeaf)
    {
        cout << node->val << " ";
    }
    else
    {
        cout << "0 ";
        printQuadTree(node->topLeft);
        printQuadTree(node->topRight);
        printQuadTree(node->bottomLeft);
        printQuadTree(node->bottomRight);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    Node *root = sol.construct(grid);

    printQuadTree(root);

    return 0;
}