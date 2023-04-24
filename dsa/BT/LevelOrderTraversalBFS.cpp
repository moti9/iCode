#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> levelOrder(Node *head)
{
    vector<vector<int>> bfs;
    queue<Node *> q;

    if (head == NULL)
    {
        return bfs;
    }
    q.push(head);
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> ds;
        for (int i = 0; i < sz; i++)
        {
            Node *node = q.front();
            q.pop();
            ds.push_back(node->data);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        bfs.push_back(ds);
    }
    return bfs;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<vector<int>> bfs = levelOrder(root);

    for (auto x : bfs)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}