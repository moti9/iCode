#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void bfs(int node, vector<int> adj[], vector<bool> &vis)
    {
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            for (auto ch : adj[node])
            {
                if (!vis[ch])
                {
                    vis[ch] = true;
                    q.push(ch);
                }
            }
        }
    }

    void dfs(int node, vector<int> adj[], vector<bool> &vis)
    {
        vis[node] = true;
        for (auto ch : adj[node])
        {
            if (!vis[ch])
            {
                dfs(ch, adj, vis);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int m = connections.size();
        if (m < n - 1)
        {
            return -1;
        }
        vector<int> adj[n];
        for (auto &x : connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> vis(false);
        int count = 0;
        // dfs(0, adj, vis);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count += 1;
                // dfs(0, adj, vis);
                bfs(i, adj, vis);
            }
        }
        // return count;
        return count - 1;
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> connections;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        connections.push_back({u, v});
    }
    Solution sol;
    cout << sol.makeConnected(n, connections) << endl;

    return 0;
}