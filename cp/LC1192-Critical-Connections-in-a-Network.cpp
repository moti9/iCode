#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using Tarojan's algorithm
// TC- O(V+2*E)
// SC- O(V+2*E)+O(3*N)

class Solution
{
    int timer = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer += 1;

        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (!vis[it])
            {
                dfs(it, node, adj, vis, tin, low, bridges);
                low[node] = min(low[it], low[node]);

                if (low[it] > tin[node])
                {
                    bridges.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[it], low[node]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n), low(n);
        vector<vector<int>> bridges;
        dfs(0, -1, adj, vis, tin, low, bridges);

        return bridges;
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
        int a, b;
        cin >> a >> b;
        connections.push_back({a, b});
    }

    Solution sol;
    vector<vector<int>> bridges = sol.criticalConnections(n, connections);
    for (auto bridge : bridges)
    {
        for (auto b : bridge)
        {
            cout << b << " ";
        }
        cout << "\n";
    }

    return 0;
}