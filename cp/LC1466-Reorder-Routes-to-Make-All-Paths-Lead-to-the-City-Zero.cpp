#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void dfs(int node, int parent, int &count, vector<vector<pair<int, int>>> &adj)
    {
        for (auto ch : adj[node])
        {
            if (ch.first != parent)
            {
                count += ch.second;
                dfs(ch.first, node, count, adj);
            }
        }
    }

    int bfs(int node, int n, vector<vector<pair<int, int>>> &adj)
    {
        int count = 0;
        vector<bool> vis(n);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while (!q.empty())
        {
            node = q.front();
            q.pop();
            for (auto &cp : adj[node])
            {
                if (!vis[cp.first])
                {
                    count += cp.second;
                    vis[cp.first] = true;
                    q.push(cp.first);
                }
            }
        }
        return count;
    }

public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto x : connections)
        {
            adj[x[0]].push_back({x[1], 1});
            adj[x[1]].push_back({x[0], 0});
        }
        // int count = 0;
        // dfs(0, -1, count, adj);
        // return count;

        return bfs(0, n, adj);
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

    cout << sol.minReorder(n, connections) << endl;

    return 0;
}