#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                if (dfs(adjNode, adj, vis, pathVis))
                {
                    return true;
                }
            }
            else if (pathVis[adjNode])
            {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V);
        vector<int> pathVis(V);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathVis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
