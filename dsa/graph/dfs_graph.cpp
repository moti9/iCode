#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void dfsTraversal(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfsTraversal(it, adj, vis, ls);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (size_t i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start = 0;

    vector<int> dfs;
    vector<bool> vis(n, 0);
    dfsTraversal(start, adj, vis, dfs);

    for (auto x : dfs)
    {
        cout << x << " ";
    }
    return 0;
}