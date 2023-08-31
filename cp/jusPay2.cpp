#include <bits/stdc++.h>
using namespace std;

long long dfs(int node, int parNode, vector<vector<int>> &adj, vector<int> &vis, vector<int> &parent, vector<int> &copyNode)
{
    vis[node] = 1;
    parent[node] = parNode;
    copyNode.push_back(node);

    for (auto &i : adj[node])
    {
        if (vis[i] == 0)
        {
            long long sum = dfs(i, node, adj, vis, parent, copyNode);
            if (sum != -1)
            {
                return sum;
            }
        }
        else if (vis[i] == 1)
        {
            long long sum = i;
            while (node != i)
            {
                sum += node;
                node = parent[node];
            }
            if (node == i)
                return sum;
            return -1;
        }
    }
    return -1;
}

void solution_function()
{
    int n;
    cin >> n;

    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++)
    {
        int edge;
        cin >> edge;
        if (edge != -1)
            adjList[i].push_back(edge);
    }

    long long sum = -1;

    vector<int> vis(n), parent(n), copyNode;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            sum = max(sum, dfs(i, -1, adjList, vis, parent, copyNode));
            for (auto &cp : copyNode)
            {
                vis[cp] = 2;
            }
            copyNode.clear();
        }
    }

    cout << sum << "\n";
}

int main()
{
    int test;
    cin >> test;

    for (int tt = 1; tt <= test; tt += 1)
    {
        solution_function();
    }
    return 0;
}
