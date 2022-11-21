#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<int> bfsTraversal(vector<int> adj[], int n)
{
    vector<bool> vis(n, 0);
    vis[0] = 1;

    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return bfs;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n]; // Zero based
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs = bfsTraversal(adj, n);

    for (auto x : bfs)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}