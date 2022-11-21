#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            count += 1;
            dfs(i, adj, vis);
        }
    }
    cout << count << "\n";

    return 0;
}