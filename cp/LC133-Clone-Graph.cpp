#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    Node *solve(Node *node, unordered_map<Node *, Node *> &mp)
    {
        if (mp.count(node))
        {
            return mp[node];
        }
        Node *temp = new Node(node->val);
        mp[node] = temp;
        for (auto it : node->neighbors)
        {
            temp->neighbors.push_back(solve(it, mp));
        }
        return temp;
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        unordered_map<Node *, Node *> mp;
        return solve(node, mp);
    }
};

int main()
{

    return 0;
}